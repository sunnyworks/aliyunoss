<?php
/**
 * @file
 * Provides Aliyun OSS configuration form.
 */

/**
 * Settings form.
 */
function aliyunoss_settings_form($form, &$form_state) {
  $form['required'] = array(
    '#type' => 'fieldset',
    '#title' => t('Aliyun OSS Bucket Info'),
  );
  $form['required']['aliyunoss_bucket'] = array(
    '#type' => 'textfield',
    '#title' => t('Aliyun Bucket ID'),
    '#default_value' => variable_get('aliyunoss_bucket', ''),
    '#required' => TRUE,
  );

  $form['cname'] = array(
    '#type' => 'fieldset',
    '#title' => t('Aliyun OSS CNAME Info'),
  );
  $form['cname']['aliyunoss_cname'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Enable CNAME support'),
    '#description'    => t('Enable it if you want to use CNAME with OSS'),
    '#default_value'  => variable_get('aliyunoss_cname', 0),
  );
  $form['cname']['aliyunoss_domain'] = array(
    '#type' => 'textfield',
    '#title' => t('CNAME Address'),
    '#default_value' => variable_get('aliyunoss_domain', ''),
  );

  $form['aliyunoss_cache'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Enable database caching'),
    '#description'    => t('Enable a local file metadata cache, this significantly reduces calls to OSS'),
    '#default_value'  => variable_get('aliyunoss_cache', 1),
  );

  return system_settings_form($form);
}
