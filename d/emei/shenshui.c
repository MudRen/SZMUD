// Code of ShenZhou
// shenshui.c ��ˮ��
// Shan: 96/6/30

inherit ROOM;

void create()
{
        set("short", "��ˮ��");
        set("long", @LONG
��ˮ��λ�ڱ��Ʒ��£���ǰ�д��ʯ����ҺȪ��Ȫ��ʯ�£��峺�ޱȣ���
�겻�ԡ�һ����������������ٲ��䣬������Χ���ߴ�ʮ���ɡ��Ա��и���
�֣��ɴ������з��£����´����
LONG
        );
        set("exits", ([
		"south" : __DIR__"fushou",
		"westup" : __DIR__"zhongfeng",
                "eastdown" : __DIR__"chunyang",
        ]));

        set("resource/water", 1);

	set("outdoors", "emei");
        set("item_desc",([
            "���ʯ"        :
"������ˮ��ǰ�Ĵ��ʯ���������������̡����С���롱���֣���˵Ϊ����\n"
"�����顣���е��������������棬�δ��ĳ�ͼ���ڴ˻Ӻ�����ġ����١����֡�\n",

	    "��ҺȪ"	:
"�������ҺȪ��Ȫˮ���ȣ��������㣬����͸�ˡ���˵���峯ʱ���й���̵�\n"
"��ʥ����̨�ڴ�ʼ�������ʦ�ھ��ݻ�������Ů��ȡ��ȪΪ���������Դ�Ȫ��\n"
"����ˮȪ����\n"
        ]));

	set("cost", 1);
        setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_drink", "drink");
}
// If someone is hurt, every drink will help to heal random(3) eff_qi

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<me->max_water_capacity()) {
            me->set("water", current_water+random(30));
            message("vision", me->name()+"����һ����ҺȪ������ȥ��\n"
            , environment(me), ({me}) );
            write("������һ����ҺȪ������ȥ��Ȫˮһ���ظ����������¶���ģ�ˬ͸������\n");
        if ((int)me->query("eff_qi") != 
            (int)me->query("max_qi"))
            me->receive_curing("qi", random(10));
        }
        else write("��һ�������˺ö���ҺȪ���Ѿ���Ҳ�Ȳ����ˡ�\n");

        return 1;
}

