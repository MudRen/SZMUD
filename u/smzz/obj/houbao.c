//��ɤ�Ӻ�
#include <ansi.h> 
inherit ITEM; 
int do_fu(string arg); 
void create()
{
set_name(RED"��ɤ�Ӻ�"NOR,({"houbao"}));
set("long",
""RED"һ��������ɤ�Ӻ�,ר������ɤ����ʹ,�ر������ƶĳ���һЩ��ͽ��ɤ�Ӻ���Ч!\n"NOR
);
set("unit", "��"); 
set("value", 100000); 
setup();
}
void init()
{
add_action("do_fu","fu"); 
}
int do_fu(string arg) 
{
object me = this_player(); 
if (arg!="houbao") 
return notify_fail(HIW"���ʲô���ҷ�����С�Ķ���!!!\n"NOR); 
if (arg=="houbao") 
me->set("water", (int)me->max_water_capacity()); 
message_vision(HIW"$N����һ����������ɤ�Ӻ�ֻ����һ�������ɵ���ֱ���ʺ�,�����ĸо���ɤ������������\n" NOR, me);
destruct(this_object()); 
return 1; 
}
