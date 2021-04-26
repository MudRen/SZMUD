// Code of ShenZhou
// dgb_book.c
// slow 2002/06/06
#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

int do_start(object me);


void create()
{
        set_name("�򹷰���", ({ "dgb book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "�򹷰��Ŀھ��������ǿڴ���������Ӽ����Ŵ򹷰������һ�������޹�����⡣\n");
                set("material", "paper");
				set("no_drop","�������������뿪�㡣\n");
				set("no_get",1);
				set("no_steal",1);
                set("value", 300000);

        }
        ::create();
}
void init()
{
  add_action("do_lingwu","lingwu");
  
}
int do_lingwu(string arg)
{
	object me;
	int cost;
        object *ob;
        object weapon;
        int i;
	me=this_player();
	 if (me->is_busy())
            return notify_fail("����æ����!\n");

	
	if(arg!=this_object()->query("id")) return notify_fail("��Ҫ����ʲô?\n");
        if(me->query_skill("dagou-bang", 1) <360)
        return notify_fail("�����򹷰������������ʽ��δ����أ�\n");
        if (me->query("wugou") > 500 ) 
        return notify_fail("���Ѿ���ȫ�����˴򹷰��ľ��С�\n");
        if (environment(me)->query("no_fight")) return notify_fail("����������ã��޷�ר������\n");
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
            if ((string)ob[i]->query("race") == "����"  && ob[i] != me )
            return notify_fail("�򹷰��ľ��пɲ����������˿���Ŷ��\n");
        }
        if( !objectp(weapon = me->query_temp("weapon")) ) 
        return notify_fail("�������޴򹷰�����������!\n");
        
        if( (string)weapon->query("id") != "dagou bang")
        return notify_fail("��������ؤ�������򹷰���������򹷰����ľ���!\n");
        if (me->query("qi")<me->query("max_qi") || me->query("jing")<me->query("max_jing"))
        return notify_fail("�������״�����ѣ�\n");
        if (me->query("neili")<me->query("max_neili") || me->query("jingli")<me->query("max_jingli"))
        return notify_fail("��ľ�����������δ��ӯ���޷�����\n");
	if(this_object()->query("master")!=me->query("id"))
	{
		me->add("max_neili",-100);
        return notify_fail(HIR"�㲻֪�ھ���ǿ��������ʽ��ͻȻ�Ŀ���˵���������ܡ�\n"NOR);

	}
if (wizardp(me)) printf("int = %d\n",me->query_int());
        message_vision(HIY"$NĬ��ھ������ô򹷰����������е����ƱȻ���......\n"NOR,me);
        if (random(me->query_int())>35 || random(20)==3)
        {
                 me->add("wugou",1);
                if (me->query("wugou")<60)
                 tell_object  (me,HIR"���ƺ��Դ򹷰����һ����һ˿����\n"NOR);
                 else if (me->query("wugou") == 60)
                 tell_object  (me,HIR"���������ʽ�����޹��е���ʽ��Ҳ��������������ˡ�\n"NOR);
                 else if (me->query("wugou")>500)
                 tell_object  (me,HIR"����������������޹������еľ��С�\n"NOR);
                 else
                 tell_object  (me,HIR"��������޹��������˸�����˽⡣\n"NOR);
        }
        else
        {
                tell_object(me,HIR"���ķ����ң��Ѿ�����Ҳ��������\n"NOR);
        }
        me->add("qi",-100);
        me->add("jing",-100);
        me->add("neili",-100);
        me->add("jingli",-100);
        if (!wizardp(me)) me->start_busy(2+random(5));
	return 1;

}
