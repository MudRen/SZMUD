// Code of ShenZhou
// ��ɽ��ɽҰ�֣�
// qfy 26/6/1996

inherit ROOM;

void create()
{
        set("short", "��ɽҰ��");
	set("long", @LONG
���ǻ�ɽ��ɽ��һƬ��ɽҰ�֣����ܶ���һ����߾��ޱȵĴ�������
��ï�ܵ�֦Ҷ�����ཻ֯�ţ���������������͸��ʹ���в�������֮�С�
�Ҳ���һ��ʯ�ڣ����������������ɽ�١�����ϸһ����ɽ�ٷ�϶����Լ
¶���ռ䣬�ƺ��Ǹ�ɽ����
LONG
        );
        set("exits", ([ /* sizeof() == 6 */
  		"enter" : __DIR__"shandong2",		
		"east" : __DIR__"yelin2",
  		"west" : __DIR__"yelin2",
	        "southeast" : __DIR__"yelin2",
       	 	"southwest" : __DIR__"yelin2",
	]));

	set("cost", 4);
        setup();
}
