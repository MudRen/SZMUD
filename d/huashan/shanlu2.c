// Code of ShenZhou
// ��ɽ��Ů��С��
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "��Ů��С��");
	set("long", @LONG
��������С�������ܵ���嶥��˼���¡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"southdown" : __DIR__"shanlu1",
  		"northup":__DIR__"siguoya",
	]));

	set("outdoors", "huashan");

	set("cost", 3);
        setup();
        replace_program(ROOM);
}
 
