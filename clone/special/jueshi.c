// Code of ShenZhou
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 * // Weapon sample for xkxII.							*
 * // Experiment by xQin on 9/99						*
 *										*
 * ����(name)����е�ĳ������ơ�ͬ��е�����ߣ�����ý�ӹС˵��˵���������	*
 * �����ơ����磺��β�����ĳ���Ӭ������ҳƷ��������ҳ���ɨ���ڹ��ƾ��ޡ���	*
 * ��ӹС˵ͨ�÷�������Ϊ������							*
 *										*
 * ����(description)����е��ģ��������Ӧ�ø���ʵ����е�����������Ρ�������	*
 * ���͡��÷��������ȵȡ�							*
 *										*
 * wield_msg��װ���ü���еʱ�Ķ���������					*
 *										*
 * unwield_msg���ջظü���еʱ�Ķ���������					*
 * �����ݡ�����װ���������ϱ�����Ӧ�ÿ�����					*
 * ��һ����һ�Եȶ�����λ�ı仯��						*
 *										*
 * ����(material)������ü���е���õ���Ҫ���ϡ�					*
 *										*
 * ��ֵ(value)����е����ۡ�ϡ�����(unique weapon)�����޼�֮����Ӧ�ñ���	*
 * �ٳ��ֵ������콣ֵһ���ƽ�������						*
 *										*
 * ����(weight)����е��������Ҫ����춸���е�Ĳ��������������˵��ͬ��Ҳ����	*
 * �˸���е�Ĳ��������������ͱ�����������Խ�ߣ�������Ҳ��Խ��ͬ�������	*
 * �϶Է������Ļ���Ҳ��֮������							*
 *										*
 * ����(sharpness)����е����ʱ�ĽӴ�������������������Ӵ����Խϸ΢����	*
 * ����Ҳ��Խ��								*
 *										*
 * Ӳ��(rigidity)����е���ϵ�Ӳ�ȣ���Ӳ�ȵ���е��ѹ�������и�ʱ�����׶ϡ�	*
 *										*
 * ����(ductile)�����Ըߵ���е��ײ��������������Ҫ������������			*
 *										*
 * ��������(special effect)������Щ�����п��Էų��������еı������Ա�Ϊ����	*
 * ��������Щ��������ô�϶Է���������Щ������ķ���Ч������Щ�������л�	*
 * �����������ҶԷ����������ȵ�...						*
 *										*
 * ��״(shape)�������̡�Ӳ��������ֱ��Բ�������ۡ��񡢴֡�ϸ����խ����	*
 * ��ȵȣ����������벹�䡣							*
 *										*
 * ���벹��������								*
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define UNIQUE	10000
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }

void create()
{
	set_name("�����ý�", ({ "jueshi haojian", "jueshi", "sword", "jian" }) );
	set_color(HIW+BLK);
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ���ĳ�������ȫ���ںڣ����Զ����ݽ�ɽׯ����ɽׯ��������ʦ��ʱ������ɵĽ���֮����\n");
		set("wield_msg", "ɲ�Ǽ䣬һ����׳ɽ�ӵĺں磬������ʼ���������һ�㣬������������ǰ��\n");
		set("unwield_msg", "����$N��$n����һֱ����ƥ���������𣬽�$n����ʵʵ�ع���������\n");
		set("unit", "��");
		set("material", "steel");
		set("value", UNIQUE);
		set("sharpness", 10);
		set("rigidity", 10);
		set("ductile", 10);
		set("shape", ({ "long", "sword" }) );
	}
	init_sword(140);
	setup();
}

int wield()
{
	object me = environment();
	object ob = this_object();
	int ret;

	if( !wizardp(me) && me->query("id") != "godness" )
	{
		message_vision(HIR"$N���ָոմ�����$n�Ľ�����ͻȻһ����������������Խ��д�������$N������Զ��$nҲ��֮������ϡ�\n"NOR, me, ob);
		me->receive_damage("qi", 500, "�������ý�������");
		me->receive_wound("qi", 100, "�������ý�������");
		ob->move(environment(me));
		return 0;
	}
	else if( ret = ::wield() )
	{
		message_vision(HIW+BLK"ֻ��$N��һ�����ڷ�����ĳ�������������ںڵĽ����������ȴ�����Ե����ƣ�\n"NOR, me);
		me->add("neili", -200);
		call_out("special_effect", 1, me);
		return ret;
	}
}

int special_effect(object me)
{
	mapping weapon_prop;
	object *obj, *inv, weapon;
	int i, j;

	obj = all_inventory(environment(me));
	for( i=0; i < sizeof(obj); i++ )
	{
		if( obj[i]==me ) continue;
		inv = all_inventory(obj[i]);
		for( j=0; j < sizeof(inv); j++ )
		{
			if( !mapp(weapon_prop = inv[j]->query("weapon_prop")) ) continue;        
			if( inv[j]->query("skill_type")!="sword" ) continue;
			if( inv[j]->query("equipped") )
			{
				if(obj[i]->query("neili") > 5000)
				{
					obj[i]->add("neili", -100);
					tell_object(obj[i], HIW"���������֮"+inv[j]->name()+HIW"�������𶯣��Ҷ���˫�ֽ��գ���û�������ɳ���\n"NOR);
					continue;  
				}
				else
				{
					tell_object(obj[i], HIW"���������֮"+inv[j]->name()+HIW"�������𶯣�����ղ�ס����Ȼ���ַɳ���\n"NOR);
					tell_room(environment(me), YEL+obj[i]->name()+"һ�����ղ�ס������"+inv[j]->name()+YEL"��Ȼ���ַɳ���\n"NOR, ({ obj[i] }));
				}
			}
			else if( obj[i]->is_character() )
				message_vision(HIY"$n��������֮"+inv[j]->name()+HIY"��Ȼ�Զ�Ծ��������$N��ǰ�ĵ��ϣ�����ָ�죡\n"NOR, me, obj[i]);
			else message_vision(HIY+inv[j]->name()+HIY"��Ȼ��$n�ɳ�������$N��ǰ�ĵ��ϣ�����ָ�죡\n"NOR, me, obj[i]);
			inv[j]->move(environment(me));
		}
	}
}