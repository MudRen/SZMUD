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
 *										*
 * ��λ(unit)����е��������λ����������ݡ������װ���������ϱ�����Ӧ�ÿ�����	*
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

#define UNIQUE  10000
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }

void create()
{
	set_name(MAG"�Ͼ���"NOR, ({ "zijing xiao", "zijing", "xiao" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ����ˮ���ƳɵĶ��������������ɫ�⻪��������һ����֪��Ʒ�������\n");
		set("wield_msg", HIM"ֻ���Ϲ�һ����$N��������һ�Ѿ�Ө��͸��$n"+HIM"�������С�\n"NOR);
		set("unwield_msg", HIM"�����Ϲ���ţ�$N�����İ�$n"+HIM"�������ᡣ\n"NOR);
		set("unit", "֧");
		set("material", "amethystum");
		set("value", UNIQUE);
		set("shape", "flute");
		set("sharpness", 2);
		set("rigidity", 3.8);
		set("ductile", 0.4);
	}
	init_sword(100);
	setup();
}

int wield()
{
	object me = environment();
	object ob = this_object();

	if( !wizardp(me) && me->query("id") != "txy" )
	{
		message_vision(MAG"����Ϲ�һ����$N����$n"MAG"�����𵴣�������Ұ�طɳ�������ॡ������ڵء�\n"NOR, me, ob);
		ob->move(environment(me));
		return 0;
	}
	else if (::wield())
	{
		return 1;
	}
		return 1;
}

#include "/d/taohua/obj/flute.h"
#include "/d/taohua/obj/music.h"
