// Code of ShenZhou
// ��ɽ��ɽ��
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "��ɽ����");
	set("long", @LONG
���ǻ�ɽ��ɽ��һƬ��ɽ���أ����ܶ���һ����߾��ޱȵĴ�����
�����һ��ʯ�ڣ��и�ɽ����
LONG
        );
        set("exits", ([ /* sizeof() == 6 */
  		"enter" : __DIR__"shandong3",		
		"east" : __DIR__"yelin2",
  		"west" : __DIR__"yelin2",
	        "southeast" : __DIR__"yelin2",
       	 	"southwest" : __DIR__"yelin2",
	]));

	set("cost", 2);
        setup();
}
