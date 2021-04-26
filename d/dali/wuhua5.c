// Code of ShenZhou
// Room: /d/dali/wuhua5.c

inherit ROOM;

void create()
{
	set("short", "¹ó±öÊÒ");
	set("long", @LONG
ÕâÊÇÒ»¼ä¹ó±öÊÒ£¬ÕâÀï´°Ã÷¼¸ÁÁ£¬ÓÃ¾ß¿¼¾¿¡£µ¥ÊÇ´°±ßÒ»¼Ü
×ÏÖñÈíé½ÒÑÊÇ¼ÛÖµ²»·Æ¡£Æ¾´°Ì÷Íû£¬ÒşÒşÓÚµ­ÑÌÖ®ÖĞ¿É¼û²ÔÉ½Ó
Óñ¾Ö·å£¬Ö»¼ûÉ½ÊÆÇåĞã£¬´ä±ÌÓûµÎ£¬ÁîÈËĞÄ¿õÉñâù¡£
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wuhua6.c",
]));
	set("no_clean_up", 0);
set("cost", 1);

	setup();
	replace_program(ROOM);
}
