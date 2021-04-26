#include <weapon.h>    
#include <ansi.h>   

inherit SWORD;     
inherit F_UNIQUE;   

void create()  
{ 
        set_name(HIM"����˫��"NOR,({ "ziqing jian", "sword" }) );
        set_weight(29000);   
        if( clonep() ) 
                set_default_object(__FILE__);
        else {   
                set("treasure", 1); 
                set("unit", "��");  
                set("value", 1000000); 
                set("unique", 1);  
                set("rigidity", 15); 
                set("sharpness", 10);
                set("weapon_prop/dodge", 10);   
                set("weapon_prop/parry", 10);
                set("material", "steel"); 
                set("wield_neili", 300);   
                set("wield_maxneili", 3000); 
                set("wield_str", 30);    
                set("wield_msg", HIM"ֻ������������һ��������˫������������ϼ��������أ�\n"NOR);                 
                set("long", HIM"����һ����������������Ľ���͸¶���������,   
������Է�(fen)��������ֱ�д�š���ϼ��������˪������\n"NOR);  
                set("unwield_msg", HIM"����˫��������â���϶�Ϊһ���ַɻ���$N�����С�\n" NOR);                        
        } 
        init_sword(800);
        setup();  
}  

void init()  
{   
    add_action("do_sub",({"fen", "��"})); 
}

int do_sub()    
{  
     object me, obj;
     me = this_player();  
     obj = this_object();
     if((int)me->query("neili") < 500)     
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֲ�������˫����\n");        
     if((int)me->query_str() < 28)
                return notify_fail("��о�ȫ����Ѫ���ڣ�ԭ���������������ֲ�������˫����\n");       

     message_vision(HIY"ֻ��$N������˫��һ�֣�һ��һ��������âһ���������������ѱ�����\n"NOR, me);  
     me->add("neili", -300);  
     new("/u/aya/obj/zi")->move(me, 1);
     new("/u/aya/obj/qing")->move(me, 1);
     destruct(obj);  
     return 1; 
}
