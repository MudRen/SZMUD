// Code of ShenZhou
// caishen.h  �ɲ�

#include <ansi.h>

void init()
{
        this_player()->delete_temp("cbshen");
        add_action("do_search", "tan");
        add_action("do_search", "search");
        add_action("do_dig", "wa");
        add_action("do_dig", "dig");
}

int do_search(string arg)
{
        object me;
        int power;

        if( !arg || !(arg == "��" || arg == "�˲�") )
                return 0;

        me = this_player();

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ�š�\n");

        if( me->query_temp("cbshen/��1") )
                return notify_fail("�㲻���Ѿ��ҵ��˲�����\n");

        if( !present("suobo gun", me) )
                return notify_fail("��û�����������޷�������ľɽ��Ѱ���˲Σ�\n");

        if( (int)me->query("jingli") < 80 )
                return notify_fail("��̫���ˣ���ЪϢһ����ɡ�\n");

        me->add_temp("cbshen/times", 1);
        me->add("jingli", -40);
        me->start_busy(1);   

        if( query("count") < 1 && (int)me->query_temp("cbshen/times") > 30 )
		return notify_fail("�������������������ܵĹ�ľ�Ӳݣ�����û�������˲ε��ټ���\n");

        message_vision("$N�����������������ܵĹ�ľ�Ӳݣ�ϣ���ܴ��з����˲ε��ټ���\n", me);

        power = (int)me->query_temp("cbshen/times") * (int)me->query("kar");
        power *= query("count");

        if( random(power) > 100 ) {
                me->set_temp("cbshen/��1", 1);
                message_vision(HIG"\n$N�ù��Ӳ��ϵĲ��������ܵ�ɽ�ݣ���Ȼ�����Ӳ�֮����һ���˲Σ�\n"NOR, me);
                write("�㲻�����˵���������������������������鳡�����" +
                       "����ԶԶ���˿�ȥ���ڴ�ɽ�лص����þò�ɢ��\n");
	}

        return 1;
}

int do_dig(string arg)
{
        object me, ob;

        if( !arg || !(arg == "��" || arg == "�˲�") )
                return 0;

        me = this_player();

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("����æ�š�\n");

        if( !(ob = present("lugu qianzi", me)) )
		return notify_fail("��û��¹��ǥ�ӣ��޷����˲δ����������\n");

        if( (int)me->query("jingli") < 80 )
                return notify_fail("��̫���ˣ���ЪϢһ����ɡ�\n");

        me->add("jingli", -60);
        me->start_busy(1);

        if( !me->query_temp("cbshen/��1") ) {
                message_vision("$N����¹��ǥ��ʹ�����������������°�һ����ǥ�Ӷ�Ϊ���أ�\n", me);
                destruct(ob);
                return 1;
        }
 
        add("count", -1);
        ob = new(DRUG_D("cb_renshen"));
	ob->move(me);
 
        message_vision(HIY"$N�ӻ����ͳ�һ��¹��ǥ�ӣ�С������İ��˲δ����������\n"NOR, me);
        me->delete_temp("cbshen");

        return 1;
}


