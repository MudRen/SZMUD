// Code of ShenZhou
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬ�������ܵ����ԣ�֦Ҷ�������أ�һ����ȥ�����˻������ǻ�������ȫ
��������档ͻȻ��ǰ��ԼĪ����Զ��һ���۾���ӨӨ���������⡣����һ������
���������������۾�ȴһ���Ͳ����ˡ����е㺦�£����ǻ�ȥ�ɡ�
LONG
	);
         set("exits", ([
                "north" : __DIR__"shidong",
     		"east" : __DIR__"caodi",
                "west" : __DIR__"harbor",
	   ]));

         set("objects", ([
                __DIR__"obj/taoshu" : 1,
        ]));

	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
