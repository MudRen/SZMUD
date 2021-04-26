// Code of ShenZhou
// Room: ssmiao.c

inherit ROOM;

string look_lingwei();

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����һ����ľ���ʯͷ�ݳɵ�С����ǰ����ɢ����һЩȼ���Ļҽ���
���﹩����ɽ��ү�ϰ�ͷ����λ(lingwei)����˵�������вɲ��˵���ʦү��
����ÿ����ɽ�ڲεĲοͶ�Ҫ��������ݣ�ϣ���ܵõ������˼ҵı��ӡ�
LONG
	);

	set("exits", ([
		"out" : __DIR__"huanglu2",
	]));
        set("item_desc",([
                "lingwei" :  (: look_lingwei :),
        ]));
        set("cost", 1);

	setup();
}

void init()
{
	add_action("do_bai", "bai");
        add_action("do_bai", "kneel");
}

int do_bai(string arg)
{
	object me = this_player();
        int power;

        if( !arg || !(arg == "lingwei" || arg == "��λ") )
                return 0;

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ�š�\n");

	message("vision", me->name() + "��������������λ���˼��ݡ�\n", environment(me), ({me}));
	write("�㹧������������λ���˼��ݡ����л������\n"
              "\n ɽ��ү�ϰ�ͷ��\n"
              "\n �����������ۡ�\n"
              "\n ��Ҫ�Ƿ��˲ƣ�\n"
              "\n ����������ɽ��ү�ϰ�ͷ��\n");
        me->add_temp("cbshen/bai", 1);
        me->start_busy(1);

        switch( (int)me->query_temp("cbshen/blw") ) {
                case 1:  return 1; break;
                case 2:  break;
                case 3:  return 1; break;
                default: me->set_temp("cbshen/blw", 2); break;
        }

        switch((int)me->query_temp("cbshen/ask_gun")) {
                case 1:   power = 2;  break;
                case 2:   power = 3;  break;
                case 3:   power = 0;  break;
                default:  power = 1;  break;
        }

        power *= (int)me->query_temp("cbshen/bai") / 3 + 1;
        power *= (int)me->query("kar");
        power = random(power);

        if( power > 100 && me->query_temp("cbshen/blw") == 2 )
                me->set_temp("cbshen/blw", 1);

        if( power < 3 && me->query_temp("cbshen/blw") == 2 )
                me->set_temp("cbshen/blw", 3);

	return 1;
}

string look_lingwei()
{
    return
    "\n"
 "**************\n"
 "*            *\n"
 "*     ɽ     *\n"
 "*     ��     *\n"
 "*     ү     *\n"
 "*     ��     *\n"
 "*     ��     *\n"
 "*     ͷ     *\n"
 "*            *\n"
 "*     ��     *\n"
 "*     ��     *\n"
 "*            *\n"
 "*     ֮     *\n"
 "*     λ     *\n"
 "*            *\n"
 "*            *\n"
 "**************\n";
    "\n";
}
