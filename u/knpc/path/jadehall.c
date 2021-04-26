// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;
string look_skeleton();
string look_sword();

void create()
{
	set("short", "�������");
	set("long", @LONG
����ϵ������Ǻ���(skeleton)�����е��µ����Ǵ��С
С��������������ǹ��ꪶ��У�ֻ����״���أ�������ϰ����
��Ȼ��ͬ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"jaderoad5",
		"north" : __DIR__"jadehall2",

	]));
	set("item_desc", ([
	"skeleton" : (: look_skeleton :),
	"white sword" : (: look_sword :),
	"sword" : (: look_sword :),
	]));
	set("jade_sword",1);
	set("cost", 1);
	setup();
}
void init()
{       
	object me, *obj, *inv;
	int i, j;
	me = this_player();
	obj = all_inventory(environment(me));
	for( i=0; i < sizeof(obj); i++ )
	{
		inv = all_inventory(obj[i]);
		for( j=0; j < sizeof(inv); j++ )
		{
			if( inv[j]->query("material") != "steel" 
			&& inv[j]->query("material") != "blacksteel" 
			&& inv[j]->query("material") != "iron" ) continue;
			if( inv[j]->query("equipped") && inv[j]->query("armor_type") == "cloth") {
			message_vision(HIW"һ�ɾ޴�Ĵ�������$N��������"+inv[j]->name()+HIW"����������һ����$N�ѱ���ɽ����ˤ���ڵأ�һʱ��Ҳ����������\n"NOR, obj[i]);
			me->add("jingli", -50);
			me->start_busy(3);
			}
			else if( inv[j]->query("equipped") && inv[j] == me->query_temp("weapon"))
			{
				message_vision(HIW"$Nͻ��һ�ɼ���������������"+inv[j]->name()+HIW"������һ����"+inv[j]->name()+HIW"�������֣����ڵ��ϣ�\n"NOR, obj[i]);
			}
			else message_vision(HIW"$N����"+inv[j]->name()+HIW"��Ȼ��һ�������������÷ɳ����һ�������ڵ��£�\n"NOR, obj[i]);
			inv[j]->move(environment(me));

			if(inv[j]->query("weapon_prop/damage") >= 1 && inv[j]->query("weapon_prop/damage") < 30 ) {
			message_vision(HIW "ֻ������ž����һ����"+inv[j]->name()+ HIW"���ڵ���ײ�ϳ����أ�\n" NOR,  obj[i] );
			inv[j]->set("name", "�ϵ���" + inv[j]->name());
			inv[j]->set("value", 0);
			inv[j]->set("weapon_prop", 0);
			}
			if(!me->is_busy()) me->start_busy(1);
		}
	}
}

string look_skeleton()
{
	string desc;
	if(query("jade_sword")) 
	desc = "һ��ֱ���ĺ��ǣ����ϻ��������������·����Ǹ���״��Ȼ������\n"
	"��������ץ��һ����ɫ����(white sword)��������һ�ߺ������ϣ���������������׽�ɱ�������ˡ�\n";
	else desc = "�����ڵ��Ͽ���һ�ѡ�\n";
	return desc;

}

string look_sword()
{
	object sword = new("/d/xingxiu/obj/yujian");
	object me = this_player();
	string desc;
	if(query("jade_sword")) {
	message_vision("$N��������Ӻ�������ȡ�������ߺ���֧��һʧ����ʱ������һ���죬����һ�ѡ�\n", me);
	sword->move(this_player());
	delete("jade_sword");
	return "";
	}
	else return "��Ҫ��ʲô��\n";
}
