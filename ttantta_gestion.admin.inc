<?php
// $Id: pathauto.admin.inc,v 1.10.2.1 2008/06/24 16:07:51 greggles Exp $

/**
 * @file
 * Admin page callbacks for the Gestión tt1 module.
 *
 * @ingroup pathauto
 */

function ttantta_gestion_form_bloques(&$form_state, $edit = array()){

//  drupal_add_css('imce-content.css');
  $bloques = module_invoke_all('mas_bloques_gestion');
  $aux = 1;
  $form['inicio_rapido'] = array(
    '#type' => 'fieldset',
    '#title' => t('Inicio rápido'),
    '#collapsible' => TRUE,
    '#prefix' => "<div class=inicio_rapido>",
    '#suffix' => "</div>",
 );
  $form['inicio_rapido']['pasos'] =array(
      '#type' => 'item',
      '#value' => theme('ttantta_gestion_inicio_rapido', 'gestion'),
    );
  
  $form['gestion'] = array(
    '#type' => 'fieldset',
    '#title' => t('Gestión'),
    '#collapsible' => TRUE,
    '#prefix' => "<div class=gestion>",
    '#suffix' => "</div>",
 );


 foreach ($bloques as $modulo => $gestion_modulo){
    if ($aux == 1) {
      $clase = 'bloque_izq';
    }
    elseif ($aux == 2){
      $clase = 'bloque_centro';
    }
    elseif ($aux == 3){
      $clase = 'bloque_drc';
      $aux = 0;
    }
    $form['gestion'][$modulo] = array(
      '#type' => 'item',
      '#value' => $gestion_modulo,
      '#prefix' => "<div class=$clase>",
      '#suffix' => "</div>",
    );
  $aux ++;
  }
  $form['estadisticas'] = array(
    '#type' => 'fieldset',
    '#title' => t('Estadísticas'),
    '#collapsible' => TRUE,
    '#prefix' => "<div class=gestion_estadisticas>",
    '#suffix' => "</div>",
  );
  $form['estadisticas']['estad'] =array(
      '#type' => 'item',
      '#value' => theme('ttantta_gestion_estadisticas', 'gestion'),
    );

  $form['configuracion'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configuraciones'),
    '#collapsible' => TRUE,
  );
  $default = variable_get('comment_noticias', '');
  $content_types = ( array_map('check_plain', node_get_types('names')));
  foreach ($content_types as $type => $type_name){
    if (variable_get('comment_'.$type, '') == 2){
      $type_comment[$type] = $type;
    }
    else {
      $type_comment[$type] = 0;
    }
  }
 $form['configuracion']['comentarios'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Comentarios en'),
    '#default_value' => $type_comment,
    '#options' => array_map('check_plain', node_get_types('names')),
    '#description' => 'Selecciona el tipo de contenido en el que se puedan dejar comentarios',
  );
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  return $form;
}


/**
 * Accept the form submission for a vocabulary and save the results.
 */
function ttantta_gestion_form_bloques_submit($form, &$form_state) {
  $comentarios = $form_state['values']['comentarios'];
  foreach ($comentarios as $type => $type_value){
    if ($type_value != '0') {
      $type_value = 2;
    }
    variable_set('comment_'.$type, $type_value);
  }
  return;
}

