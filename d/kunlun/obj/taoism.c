// Code of ShenZhou
// ���¾��϶���.c 
// keny

inherit ITEM; 
inherit F_UNIQUE; 
#include <ansi.h> 

int do_read(string arg); 

void create() 
{
set_name(HIB"���¾������վ�"NOR, ({ "daode jing", "jing" }));
set_weight(600); 
if( clonep() ) 
set_default_object(__FILE__); 
else { 
set("unit", "��"); 
set("long", "���Ǵ��������ɵ��������õĵ��¾������վ����ഫ�ǹ��˻��˼�ʮ��ʱ�����ϱ�ġ�\n");
set("value", 1000000); 
set("material", "paper"); 
set("skill", ([
"name": "taoism",        // name of the skill 
"exp_required": 10000,  // minimum combat experience required 
"jing_cost":    20,     // jing cost every time study this 
"difficulty":   30,     // the base int to learn this skill
"max_skill":   150   // the maximum level you can study
]) );
}
}

void init()
{
add_action("do_du", "du"); 
add_action("do_du", "study");
}

int do_du(string arg) 
{
object me = this_player(); 

if (me->query("family/family_name")!="������") 
{
message_vision("$N������֭Ҳ���������Ȿ$n��\n",me,this_object()); 
return 1; 
}
if (!id(arg)) { 
write("��Ҫ��ʲô��\n"); 
return 1;
}
}
