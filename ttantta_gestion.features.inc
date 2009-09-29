<?php

/**
 * Implementation of hook_content_default_fields().
 */
function ttantta_gestion_content_default_fields() {
  module_load_include('inc', 'ttantta_gestion', 'ttantta_gestion.defaults');
  return _ttantta_gestion_content_default_fields();
}

/**
 * Implementation of hook_views_default_views().
 */
function ttantta_gestion_views_default_views() {
  module_load_include('inc', 'ttantta_gestion', 'ttantta_gestion.defaults');
  return _ttantta_gestion_views_default_views();
}

/**
 * Implementation of hook_user_default_permissions().
 */
function ttantta_gestion_user_default_permissions() {
  module_load_include('inc', 'ttantta_gestion', 'ttantta_gestion.defaults');
  return _ttantta_gestion_user_default_permissions();
}

