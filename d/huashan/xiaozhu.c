// Code of ShenZhou
// Room: xiaozhu.c ��ɽС��
// qfy July 25, 1996.

inherit ROOM;

void create()
{
    set("short", "��ɽС��");
    set("long", @LONG
��ɽС���ǻ�ɽ��λ���ϵı�������������򵥣�ȴ������Ȼ��С��
���и�С��������ֻ���е��ڳ����߷��裬�е�վ�ڳ�����ЪϢ����λ��
�ϲ�ϲ�����˴��ţ�����ɽ����Ҳ���ٵ��á�
LONG
    );

    set("exits", ([
	"east" : __DIR__"xiaolu2",
    ]));

    set("objects", ([
	CLASS_D("huashan") + "/gaolao" : 1,
	CLASS_D("huashan") + "/ailao" : 1,
    ]));

    set("no_clean_up", 0);

    set("cost", 0);
    setup();
    //replace_program(ROOM);
}

void init()
{
	object me = this_player();

   	if ( interactive(me) && me->query("huashan/job_pending") ) {
		me->set_temp("hz_job/xiaozhu", 1);
   	}
}
