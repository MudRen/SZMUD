// Code of ShenZhou
// fumo-dao.c ��ħ��

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;

void create()
{
	set_name("��ħ��", ({ "fumo dao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������ѩ���ķ�ħ�������м�������Ѫ��������������ƥ��
ӳ���������˵�������ǰ�ɴ�Ħ����Я����ԭ��һ·��֮������ħ��
���Ƿ�����Ͻ�ħ������\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 100000);
		set("wield_msg", HIY "ֻ�������һ������ħ�����ʷɳ�������Ծ��$N���С�
˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n" NOR);
		set("unwield_msg", HIY "��ħ����$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�\n" NOR);
		set("clone_ob", "/clone/weapon/fumo-dao");
		set("shaolin", 1);
	}
	init_blade(270);
	setup();
	::create();
}
