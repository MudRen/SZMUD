// Code of ShenZhou
// yuzhen.c �䵱���湬
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "���湬");
	set("long", @LONG
	�����ǽ����䵱ɽ�ĵ�һ���������湬�����ޱȣ�����ǧ��ʳ�ޣ�
�ǽ���͵�һ��Ъ�Ŵ������й������������������������˱չ��Ѿã�����
��֪���Ƿ������˼䣬��䴫˵���ѵõ����ţ�����Ĥ�ݡ�
LONG
	);
	
    set("indoors", "wudang");

	set("exits", ([
		"southup" : __DIR__"bailin",
		"northdown" : __DIR__"shijie1",
	]));
	
	set("objects", ([
		CLASS_D("wudang")+"/zhixiang" : 1 ]));
		
	set("cost", 3);
	setup();
}


int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");


    if ( dir == "southup" && me->query("wudang/offerring") < me->query("age")
	&& me->query("title") != "�䵱��ͯ"
	&& me->query("family/family_name") != "�䵱��"
        && objectp(present("zhixiang daozhang", environment(me)))
        && !objectp(present("incense", me)) )
    {
        return notify_fail("��������ȵ����粻����ɽ���㣬������أ�\n");
    }
    

    return ::valid_leave(me, dir);
}

