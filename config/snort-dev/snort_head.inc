<?php
/* 
 *   if user has selected a custom template, use it.
 *   otherwise default to pfsense tempalte
 */
if($config['theme'] <> "")
	$g['theme'] = $config['theme'];
else
	$g['theme'] = "pfsense";
	
$apple_ua = array("iPhone","iPod");
foreach($apple_ua as $useragent)
	if(strstr($_SERVER['HTTP_USER_AGENT'], $useragent))
		$g['theme'] = "pfsense";	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
	<title><?=gentitle($pgtitle);?></title>
	<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
	<link rel=”apple-touch-icon” href=”/themes/<?php echo $g['theme']; ?>/apple-touch-icon.png”/>
	
<!-- snort custom javascript and css -->
<?php include('/usr/local/pkg/snort/snort_headbase.inc'); ?>

<!-- remove Only used to test conflicts -->

        <?php 
        if (strpos($_SERVER["SCRIPT_FILENAME"], "wizard.php") !== false &&
        	file_exists("{$g['www_path']}/themes/{$g['theme']}/wizard.css")):
         ?>
        <link rel="stylesheet" href="/themes/<?php echo $g['theme']; ?>/wizard.css" media="all" />
        <?php else: ?>
        <link rel="stylesheet" href="/themes/<?php echo $g['theme']; ?>/all.css" media="all" />
        <?php endif; ?>
	<link rel="stylesheet" type="text/css" href="/niftycssprintCode.css" media="print" />
	<script type="text/javascript">var theme = "<?php echo $g['theme']; ?>"</script>
	<script type="text/javascript" src="/themes/<?php echo $g['theme']; ?>/loader.js"></script>
	
<?
	/*
	 *	Find all javascript files that need to be included
	 *	for this page ... from the arrays ... :)
	 *	Coded by: Erik Kristensen
	 */

	$dir  = trim(basename($_SERVER["SCRIPT_FILENAME"]), '.php');
	$path = "/usr/local/www/javascript/" . $dir . "/";
	if (is_dir($path)) {
		if ($dh = opendir($path)) {
			while (($file = readdir($dh)) !== false) {
		   		if (is_dir($file)) continue;
				echo "\t".'<script type="text/javascript" src="/javascript/'.$dir.'/'.$file.'"></script>'."\n";
			}
			closedir($dh);
		}
	}

	if ($oSajax):
?>
	<script language="javascript" type="text/javascript">
		<?php $oSajax->sajax_show_javascript(); ?>
	</script>
<?	endif; ?>

<?php if (!isset($closehead)){ ?>
</head>
<?php } ?>