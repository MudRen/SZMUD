// Code of ShenZhou
// guimei_book.c
//Wzfeng@xkx 99 11
#include <ansi.h>
inherit ITEM;

int do_start(object me);


void create()
{
	set_name("�����ķ�", ({ "guimei xinfa", "xinfa" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long", "����һ����ȱ��ȫ��С����,��������ű�а����ʧ���ѾõĹ����ķ���\n");
		set("material", "paper");
		set("no_drop","�������������뿪�㡣\n");
		set("no_get",1);
		set("no_steal",1);
		set("value", 300000);
	}
}
void init()
{
  add_action("do_lingwu","lingwu");
  
}
int do_lingwu(string arg)
{
	object me;
	int cost;
	me=this_player();
	if (me->is_busy()) return notify_fail("����æ����!\n");
	if(arg!=this_object()->query("id")) return notify_fail("��Ҫ����ʲô?\n");
	if(me->query_skill("pixie-jian", 1) <120) return notify_fail("��ı�а����������죬�޷������ķ��еİ��\n");
	if(this_object()->query("master")!=me->query("id"))
	{
		me->add("max_neili",-100);
		return notify_fail(HIR"��һ��֮��ֻ���������ȣ��������ۣ�˵���������ܡ�\n"NOR);
	}
	if(this_player()->query_temp("linji/zhixin") || this_player()->query_temp("linji/fengyun"))
	{
		me->add("max_neili",-100);
		me->add("max_jingli",-100);
		return notify_fail(HIR"��ͻȻ���ֻ�����������˵�������ѹ���ת�ۼ��ƺ�Ҫ��Ϣ��\n"NOR);
	}
	if(me->query("canuse_guimei")==1) return notify_fail("���Ѿ���������ķ��ľ�Ҫ��\n");
	if(me->query("neili")<1500||me->query("jingli")<1500) return notify_fail("�㾫�񲻼ѣ��޷������ķ��еİ��\n");
	cost=me->query("int");
	if(cost>=30) cost=5;
	else cost=35-cost;
	me->set_temp("guimei_cost",cost);
	message_vision(HIB "$N�ӻ�������һ��С����,ϸϸ�Ŀ���,����¶���������ɫ��\n" NOR, me);
	me->start_busy((: do_start:));
	return 1;
}

int do_start(object me)
{
	if(me->query_temp("guimei_cost")<=0)
	{
		if(random(me->query("dex"))>19||random(me->query_dex())>40)	
		{
			me->add("pixie-guimei",1);
			message_vision(HIB "$N�͵����Ծ��,�ڿ��лû��ɼ�����Ӱ�����Ա任�˼���а���ޱȵ����ơ�\n" NOR, me);
			if(me->query("pixie-guimei")>=15)
			{
				tell_object  (me,HIY"����������������ķ��ľ�Ҫ��\n"NOR);
				if(me->query("canuse_guimei")!=1)
        log_file("static/AddGift", sprintf("[%s]   %s   %s(%s)����а�������ȵ� һ ������\n",
                ctime(time())[0..15], me->query("family/family_name"), me->name(), geteuid(me)));
me->add("AddGift/piexie/dex",1);
				me->add("dex",1);
				me->set("canuse_guimei",1);
				me->delete("pixie-guimei");
				
			}
			me->set("neili",0);
			me->set("jingli",0);
		}
		else
		{
			
			message_vision(HIB "$N�͵����Ծ��,�ڿ��лû��ɼ�����Ӱ��ͻȻ��˫��һ�飬����ˤ��������\n" NOR, me);
		    me->unconcious();

		}
	return 0;
	}
	me->add_temp("guimei_cost",-1);
	return 1;
}
