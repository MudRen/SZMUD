// Code of ShenZhou
// ��ɽС��
// qfy 22/7/1996

inherit ROOM;

void create()
{
        set("short", "��ɽС��");
	set("long", @LONG
���ǻ�ɽ��ɽ��һ��С�����˼�����������Ұ�������������飬Ҫ��
�����˴��죬˭Ҳ�벻�����ﾹȻ����С����
LONG
        );

	set("outdoors", "huashan");

        set("exits", ([ /* sizeof() == 1 */
  	"north":__DIR__"taogu",
]));

	set("cost", 2);
        setup();
        replace_program(ROOM);
}
 
