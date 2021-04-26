// Code of ShenZhou
// youlong.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIW"��֪��"NOR, ({ "xianzhi sword", "xianzhi", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ������ɫ�ı�����һ���������Ĺ�â�ڽ����ϲ�ͣ�����ߣ�����һ�������Ļ��������\n��ľ���������Ӱ�죬���к����ڣ�ronghe��Ϊһ��ĳ嶯��\n");
                set("value", 1000);
                set("material", "blacksteel");
		set("rigidity", 100);
                set("wield_msg", 
                        HIW"һ���貵İ�ɫ���ߴӾ��µĽ���৵�һ��������$N�����У����׵Ľ�����˸��һ�ַ·���֪�Ⱦ��������������\n"NOR);
                set("unequip_msg", HIW"��֪������һ�����׵Ĺ�â���뽣�ʡ�\n"NOR);
                set("unwield_msg", HIW"��֪������һ�����׵Ĺ�â���뽣�ʡ�\n"NOR);
        }

        init_sword(110);
        setup();
}

void init()
{
        if( this_player() == environment() )
                add_action("do_ronghe", "ronghe");
}

int do_ronghe(string arg)
{
        object me = this_player();

        if ( arg != "xianzhi sword" && arg != "xianzhi" && arg != "sword")
        return notify_fail("��Ҫ��ʲô�����ںϡ�\n");

        if ( me->query_temp("xianzhi_ronghe") )    {
        write("���Ѿ�����֪����Ϊһ���ˡ�\n");return 1;}

        message_vision(HIW"$N����ȫ���������֪�������������Ϊһ�壬��������ʱ������̥���ǵı仯��\n"NOR,me);
        me->add_temp("apply/intelligence", 5);
        me->add_temp("apply/dexerity", 5);
        me->add_temp("apply/attack", 5);

        remove_call_out("recover");
        call_out("recover", 1800 , me);
       me->set_temp("xianzhi_ronghe",1);
        return 1;
}

void recover(object me)
{
        me->add_temp("apply/intelligence", -5);
        me->add_temp("apply/dexerity", -5);
        me->add_temp("apply/attack", -5);
        me->delete_temp("xianzhi_ronghe");
        tell_object(me,HIW"�㾫��һ��и����ʱ����֪���������ں�״̬��\n"NOR);
}


