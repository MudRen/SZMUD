// Code of ShenZhou
// heilong-bian.c ������

#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
	set_name("������", ({ "heilong bian", "bian" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"����һ���ں������ĳ��ޣ��˺ڽ��������˷���ѩɽ���˿��֯���ɡ�
�ݴ��������־��ֱ���ʦ������а��ÿ�ν����޶񣬼�������ȣ�����
�䷢��֯�˱ޡ������������������ɴ����ޡ����߽�Ϲ��ۣ������ޱȡ�\n");
		set("value", 100000000);
		set("material", "leather");
		set("rigidity", 1000);
		set("no_sell", 1);
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/heilong-bian.c");
//***** END OF ADDING *****
		set("wield_msg", HIR "$N����һ����һ�������ĺ�����������չ������������ڿ�������������\n" NOR);
		set("unwield_msg", HIR "�������ڰ����һת����ৡ���û��$N�����С�\n" NOR);
		set("shaolin", 1);
        }
        init_whip(50);
        setup();
}
