<?php

/**
 * Helper to implemetation of hook_content_default_fields().
 */
function _ttantta_gestion_content_default_fields() {
 $fields = array();
  if(variable_get('ttantta_gestion', '') != 1){

  $fields[]  = array (
    'label' => 'Imagen',
    'field_name' => 'field_noticias_imagen',
    'type_name' => 'noticias',
    'type' => 'filefield',
    'widget_type' => 'imagefield_widget',
    'change' => 'Change basic information',
    'weight' => '-1',
    'file_extensions' => 'jpg jpeg png gif',
    'progress_indicator' => 'bar',
    'file_path' => '',
    'max_filesize_per_file' => '',
    'max_filesize_per_node' => '',
    'max_resolution' => 0,
    'min_resolution' => 0,
    'custom_alt' => 0,
    'alt' => '',
    'custom_title' => 0,
    'title_type' => 'textfield',
    'title' => '',
    'use_default_image' => 0,
    'default_image_upload' => '',
    'default_image' => NULL,
    'description' => '<p class="ayuda-link">
    <p class="enlace">Ayuda</p></p>
    <p class="descripcion"> Adjunte la imagen de la noticia.</p>',
    'group' => false,
    'required' => 0,
    'multiple' => '0',
    'list_field' => '1',
    'list_default' => 1,
    'description_field' => '0',
   'op' => 'Guardar configuraciones del campo',
    'module' => 'filefield',
    'widget_module' => 'imagefield',
    'columns' =>
    array (
      'fid' =>
      array (
        'type' => 'int',
        'not null' => false,
        'views' => true,
      ),
      'list' =>
      array (
        'type' => 'int',
        'size' => 'tiny',
        'not null' => false,
        'views' => true,
      ),
      'data' =>
      array (
        'type' => 'text',
      'serialize' => true,
        'views' => true,
      ),
    ),

   'display_settings' =>
    array (
      'weight' => '-1',
      'parent' => '',
      4 =>
      array (
        'format' => 'hidden',
        'exclude' => 1,
      ),
      'label' =>
      array (
        'format' => 'hidden',
      ),
      'teaser' =>
      array (
        'format' => 'noticias_teaser_linked',
        'exclude' => 0,
      ),
      'full' =>
      array (
        'format' => 'noticias_full_default',
        'exclude' => 0,
      ),
      'token' =>
      array (
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
 );

variable_set('ttantta_gestion', 1);
  return $fields;
}
}


/**
 * Helper to implemetation of hook_views_default_views().
 */
function _ttantta_gestion_views_default_views() {
$view = new view;
$view->name = 'gestion_noticias';
$view->description = '';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'title' => array(
    'label' => 'Noticia',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
  'created' => array(
    'label' => 'Publicado',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'date_format' => 'custom',
    'custom_date_format' => 'd/m/Y h:i',
    'exclude' => 0,
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
    'relationship' => 'none',
  ),
  'edit_node' => array(
    'label' => 'Editar',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'text' => '',
    'exclude' => 0,
    'id' => 'edit_node',
    'table' => 'node',
    'field' => 'edit_node',
    'relationship' => 'none',
  ),
  'delete_node' => array(
    'label' => 'Borrar',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'text' => '',
    'exclude' => 0,
    'id' => 'delete_node',
    'table' => 'node',
    'field' => 'delete_node',
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'noticias' => 'noticias',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
  ),
));
$handler->override_option('access', array(
  'type' => 'role',
  'role' => array(
    '3' => 3,
  ),
));
$handler->override_option('title', 'Gestión Noticias');
$handler->override_option('footer', '<a href="/gestion">Volver a mi panel de control.</a>');
$handler->override_option('footer_format', '1');
$handler->override_option('footer_empty', 0);
$handler->override_option('empty', 'No ha añadido todavía ninguna noticia.
<a href="/gestion">Volver a mi panel de control.</a>');
$handler->override_option('empty_format', '1');
$handler->override_option('items_per_page', 30);
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'table');
$handler = $view->new_display('page', 'Página', 'page_1');
$handler->override_option('path', 'gestion/noticias');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));
  $views[$view->name] = $view;

$view = '';
$handler = '';

$view = new view;
$view->name = 'gestion_paginas';
$view->description = '';
$view->tag = '';
$view->view_php = '';
$view->base_table = 'node';
$view->is_cacheable = FALSE;
$view->api_version = 2;
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
$handler = $view->new_display('default', 'Defaults', 'default');
$handler->override_option('fields', array(
  'title' => array(
    'label' => 'Título',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'link_to_node' => 1,
    'exclude' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'relationship' => 'none',
  ),
  'created' => array(
    'label' => 'Creado el',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'date_format' => 'custom',
    'custom_date_format' => 'd/m/Y h:i',
    'exclude' => 0,
    'id' => 'created',
    'table' => 'node',
    'field' => 'created',
    'relationship' => 'none',
  ),
  'edit_node' => array(
    'label' => 'Editar',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'text' => '',
    'exclude' => 0,
    'id' => 'edit_node',
    'table' => 'node',
    'field' => 'edit_node',
    'relationship' => 'none',
  ),
  'delete_node' => array(
    'label' => 'Borrar',
    'alter' => array(
      'alter_text' => 0,
      'text' => '',
      'make_link' => 0,
      'path' => '',
      'alt' => '',
      'prefix' => '',
      'suffix' => '',
      'help' => '',
      'trim' => 0,
      'max_length' => '',
      'word_boundary' => 1,
      'ellipsis' => 1,
      'strip_tags' => 0,
      'html' => 0,
    ),
    'text' => '',
    'exclude' => 0,
    'id' => 'delete_node',
    'table' => 'node',
    'field' => 'delete_node',
    'relationship' => 'none',
  ),
));
$handler->override_option('filters', array(
  'type' => array(
    'operator' => 'in',
    'value' => array(
      'pagina' => 'pagina',
    ),
    'group' => '0',
    'exposed' => FALSE,
    'expose' => array(
      'operator' => FALSE,
      'label' => '',
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'relationship' => 'none',
    'override' => array(
      'button' => 'Override',
    ),
  ),
));
$handler->override_option('access', array(
  'type' => 'role',
  'role' => array(
    '3' => 3,
  ),
));
$handler->override_option('title', 'Gestión Páginas');
$handler->override_option('footer', '<a href="/gestion">Volver a mi panel de control.</a>');
$handler->override_option('footer_format', '1');
$handler->override_option('footer_empty', 0);
$handler->override_option('empty', 'No ha añadido todavía ninguna página.
<a href="/gestion">Volver a mi panel de control.</a>');
$handler->override_option('empty_format', '1');
$handler->override_option('items_per_page', 30);
$handler->override_option('use_pager', '1');
$handler->override_option('style_plugin', 'table');
$handler->override_option('style_options', array(
  'grouping' => '',
  'override' => 1,
  'sticky' => 0,
  'order' => 'desc',
  'columns' => array(
    'title' => 'title',
    'created' => 'created',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  ),
  'info' => array(
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'edit_node' => array(
      'separator' => '',
    ),
    'delete_node' => array(
      'separator' => '',
    ),
  ),
  'default' => 'created',
));
$handler = $view->new_display('page', 'Página', 'page_1');
$handler->override_option('path', 'gestion/paginas');
$handler->override_option('menu', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
  'name' => 'navigation',
));
$handler->override_option('tab_options', array(
  'type' => 'none',
  'title' => '',
  'description' => '',
  'weight' => 0,
));

  $views[$view->name] = $view;

  return $views;
}



/**
 * Helper to implemetation of hook_user_default_permissions().
 */
function _ttantta_gestion_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog content
  $permissions[] = array(
    'name' => 'administer panel gestion',
    'roles' => array(
      '0' => 'gestion',
    ),
  );

  return $permissions;
}


