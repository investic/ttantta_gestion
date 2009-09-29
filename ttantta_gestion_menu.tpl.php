<? global $user; ?>
<?php if ($logged_in): // si esta logado sale el menu de gestion ?> 
  <div class="fondo-wrapper">
  <div class="fondo"> </div>
    <div class="menu_usuario">
       <div class="menu_usuario_enlace"><a href="/user">Usuario: <? print $user->name ?> </a></div>
       <div class="menu_usuario_gestion"><a href="/gestion">Panel de gestión</a></div>
       <div class="menu_usuario_logout"><a href="/logout">Cerrar sesión</a></div>
    </div>
   </div>
<?php endif; ?> 
