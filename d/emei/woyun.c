// Code of ShenZhou
// woyun.c ������
// Shan: 96/06/25

inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
�������Ա��и�����Ȫ����˵��ǰ������ˮ�˶���ɺԣ�����Ϊ֮�о�����
��Ȫˮ���������������ֱ��Ƕù�̨���Ա��ǻ����֡�
LONG
	);
	set("exits", ([
		"northeast" : __DIR__"jinding",
		"southeast" : __DIR__"huazang",
		"out" : __DIR__"duguang2",
	]));

        set("resource/water", 1);

        set("objects", ([
                "/kungfu/class/emei/jingxuan.c" :1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "emei" );

	set("cost", 1);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_song", "song");
        add_action("do_song", "read");
}

int do_song(string arg)
{
        object me = this_player();
        int level, check;
        object ob;

        level = (int)me->query_skill("linji-zhuang",1);
        check = level*level*level;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("���޷���ս����ר�������ж���֪��\n");

	if (!arg || arg != "jing" || !objectp(ob = present("maha jing", me)) )
                return notify_fail("��Ҫ��ʲô��\n");

        if( !me->query_skill("literate", 1) )
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");

	if( me->query("jing") < 100)
		me->unconcious();
	
	me->receive_damage("jing",100, "�о�ʱ���񲻼��У�����");

	message_vision("$N�ϵ��ھ����о���\n", me);

        if ( level >= 100  && check < (int)me->query("combat_exp")*10 
	&& SKILL_D("linji-zhuang")->valid_learn(me) )
                me->improve_skill("linji-zhuang", 1);

        return 1;

}
