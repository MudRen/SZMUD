// Code of ShenZhou
// cloth.c

#include <armor.h>

inherit EQUIP;

void setup()
{
        if( clonep(this_object()) ) return;

        set("armor_type", TYPE_CLOTH);
        if( !query("armor_apply/dodge")
        &&      weight() > 3000 )
                set("armor_prop/dodge", - weight() / 3000 );
}

void init()
{
        add_action("do_tear", "tear");
}

int do_tear(string str)
{
        object ob;

        if( !id(str) ) return 0;

        if( (string)query("material") != "cloth" )
                return notify_fail("��ֻ��˺���ϵ��·���\n");

        if( (int)query("teared_count") >= 4 )
                return notify_fail( name() + "����ڣ��¡��Ѿ�û�ж��ŵĲ���˺�ˡ�\n");

        message_vision("$N��" + name() + "˺��һ��������\n", this_player() );
        add("teared_count", 1);
        ob = new("/clone/misc/bandage");
        ob->set_name("��" + name() + "˺�µĲ���", ({ "cloth piece", "piece", "cloth" }) );
        if( !ob->move(this_player()) )
                ob->move(environment(this_player()));
        return 1;
}


//the following modified by haowen to provide poison apply to a cloth
int is_special() {return 1;}

mixed hit_by(object me, object victim, int damage, object weapon)

{       object ob;
        string result;
        if (!ob=victim->query_temp("armor/cloth"))
                 return damage;
        if ( weapon )
                return damage;
        if (ob->query("poison_amount")>0)
                {
                result = "ֻ��"+me->query("name")+"��ɫ���࣬��ɫ�Ź֣������ж������ӡ�\n";
                me->apply_condition("xx_poison",ob->query("poison_amount")/2+me->query_condition("xx_poison"));
                ob->set("poison_amount",ob->query("poison_amount")/2);
                if (ob->query("poison_amount")<=0)
                         ob->delete("poison_amount");
                return ([ "result": result, "damage": damage ]);
               }
         else  
               return damage;
}