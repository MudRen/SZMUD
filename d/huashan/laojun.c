// Code of ShenZhou
// laojun.c

inherit ROOM;

void create()
{
        set("short", "�Ͼ���");
	set("long", @LONG
��������Ҫ�������£�������������ЪϢ���Ͼ�����һ������೤��
ɽ�����ഫΪ̫���Ͼ������������Ͼ�����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"baichi",
  "southup" : __DIR__"husun",
]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        set("fjing", 1);

	set("cost", 4);
        setup();
        replace_program(ROOM);
}
 
