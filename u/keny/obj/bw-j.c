#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD; 

int query_autoload() { return 1; }
void create() 
{
set_name(HIY"����֮��"NOR, ({ "baiwang jian", "jian", "sword" }) ); 
set_weight(5000);
if( clonep() ) set_default_object(__FILE__); 
else 
{
set("unit", "��"); 
set("long", "���ǰ���֮�����ǰݽ�ɽׯ�Ľ������ǵ���ݽ�ɽ��һ�����ʯ�����ɵģ����ھ����ý�ͬ��һ����\n");
set("value", "2000"); 
set("rigidity", 5000000);
set("material", "steel"); 
set("wield_msg", HIW"$N�����ӽ�����γ�"+HIY"����֮��"+HIW"����ʱһ�ɱ��˵����ƴӽ��б������ܵ��ˡ�\n"NOR);
set("unwield_msg", HIY"$N��$n�Ż��˽����\n"NOR,);
set("unequip_msg", HIY"$N��$n�Ż��˽����\n"NOR,); 
}
init_sword(500);
setup(); 
}
int wield()
{
object me = environment();
object ob = this_object(); 

if( me->query("id") != "keny" ) 
{
message_vision(MAG"ͻȻ�������ڶ����ݣ�������ʶ��$N�����������ˣ�������Ұ�طɳ�������ॡ������ڵء�\n"NOR, me, ob); 
ob->move(environment(me)); 
return 0;
}
else if (::wield()) 
{ 
return 1;
}
return 1; 
}
