#include <weapon.h>   
#include <ansi.h>  

inherit SWORD;  
inherit F_UNIQUE; 
void create()
{
        set_name(HIG"��˪��"NOR,({ "qingshuang jian", "sword" }) );   
        set_weight(15000);
        if( clonep() )  
                set_default_object(__FILE__);  
        else {    
                set("treasure", 1);   
                set("unit", "��"); 
                set("value", 500000);      
                set("unique", 1);
                set("rigidity", 7);
                set("sharpness", 7);
                set("weapon_prop/dodge", 5);  
                set("weapon_prop/parry", 5);
                set("material", "steel"); 
                set("wield_neili", 100);
                set("wield_maxneili", 2000);  
                set("wield_str", 25);  
                set("wield_msg",HIG"ֻ������ৡ���һ����$N��ӯһЦ�������������,��˪������$N�����У�\n"NOR);               
                set("long", HIG"�������������������һ����˪�������桾��˪��������  
����ҵ���ϼ����Ӧ�ÿ��Խ����ѱ���(��)������\n"NOR); 
                set("unwield_msg", HIG"��˪�����շɳ����ַɻ���$N�����С�\n"NOR);        
        } 
        init_sword(400); 
        setup();   
}
