// Code Of ShenZhou
// 76ers
// keny for fun

#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
set_name("��ʮ������������" , ({"76er ball shirt", "cloth", "ball cloth" }) );
set_color("$WHT$");
set_weight(1000);
if( clonep() ) 
set_default_object(__FILE__); 
else { 
set("long", "�����ʮ������������,�ǰ��������������������£�������ӡ��76ers���ۣ���������һ������3�֣���ӡ��Iverson�����֡�\n");
set("unit", "��");
set("value", 300); 
set("material", "cloth"); 
set("armor_prop/armor", 1000); 
set("armor_prop/personality", 100); 
set("keny_only", 1); 
}
setup();
}
