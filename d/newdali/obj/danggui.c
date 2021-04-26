// Code of ShenZhou
// danggui.c ����

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void init();

void create()
{
        set_name( GRN "����" NOR , ({"dang gui", "danggui"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ð�����ϵ��飬��Ȼ�Ѿ��ɱ񣬵������������ҩЧ���ѡ�\n");
                set("value", 10000);
                set("medicine", 1);
        }
        setup();
}

int cure_ob(object me)
{
        if ( (int)me->query_condition("bonze_drug" ) > 0 ){
                me->add("max_jingli", -1);
                me->add("eff_jingli", -1);
                me->apply_condition("bonze_drug", 30);
        message_vision(HIR "$N����һ�ŵ��飬ֻ���øγ���ϣ��������ѣ�ԭ����ʳ̫��ҩ�ҩЧ�ʵ��䷴��\n" NOR, this_player());
                destruct(this_object());
        }
        me->add("max_jingli", 1);
        me->add("eff_jingli", 1);
        me->set("jingli", (int)me->query("max_jingli")*2);
        tell_object(me, HIY"�����һ���ϵ��飬һ������ֱ����¥��ȫ��ľ������ָ��ˡ�\n" NOR);

        destruct(this_object());
        return 1;
}
