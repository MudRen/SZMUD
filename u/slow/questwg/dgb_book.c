// Code of ShenZhou
// dgb_book.c
// slow 2002/06/06
#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

int do_start(object me);


void create()
{
        set_name("打狗棒谱", ({ "dgb book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
        set("long", "打狗棒的口诀向来都是口传，这个册子记载着打狗棒的最后一招天下无狗的详解。\n");
                set("material", "paper");
				set("no_drop","这样东西不能离开你。\n");
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
            return notify_fail("你正忙着呢!\n");

	
	if(arg!=this_object()->query("id")) return notify_fail("你要领悟什么?\n");
        if(me->query_skill("dagou-bang", 1) <360)
        return notify_fail("你连打狗棒法最基本的招式还未娴熟呢？\n");
        if (me->query("wugou") > 500 ) 
        return notify_fail("你已经完全领悟了打狗棒的绝招。\n");
        if (environment(me)->query("no_fight")) return notify_fail("这里空气不好，无法专心领悟。\n");
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
            if ((string)ob[i]->query("race") == "人类"  && ob[i] != me )
            return notify_fail("打狗棒的绝招可不能轻易让人看的哦。\n");
        }
        if( !objectp(weapon = me->query_temp("weapon")) ) 
        return notify_fail("你手中无打狗棒如果领悟绝招!\n");
        
        if( (string)weapon->query("id") != "dagou bang")
        return notify_fail("手中拿着丐帮至宝打狗棒才能领悟打狗棒法的绝招!\n");
        if (me->query("qi")<me->query("max_qi") || me->query("jing")<me->query("max_jing"))
        return notify_fail("你的身体状况不佳！\n");
        if (me->query("neili")<me->query("max_neili") || me->query("jingli")<me->query("max_jingli"))
        return notify_fail("你的精力，内力还未充盈，无法领悟！\n");
	if(this_object()->query("master")!=me->query("id"))
	{
		me->add("max_neili",-100);
        return notify_fail(HIR"你不知口诀，强行领悟招式，突然心口有说不出的难受。\n"NOR);

	}
if (wizardp(me)) printf("int = %d\n",me->query_int());
        message_vision(HIY"$N默念口诀，手拿打狗棒，按照书中的姿势比划着......\n"NOR,me);
        if (random(me->query_int())>35 || random(20)==3)
        {
                 me->add("wugou",1);
                if (me->query("wugou")<60)
                 tell_object  (me,HIR"你似乎对打狗棒最后一招有一丝领悟。\n"NOR);
                 else if (me->query("wugou") == 60)
                 tell_object  (me,HIR"你领悟出六式天下无狗中的三式，也许你该试验试验了。\n"NOR);
                 else if (me->query("wugou")>500)
                 tell_object  (me,HIR"你终于领悟出天下无狗的所有的绝招。\n"NOR);
                 else
                 tell_object  (me,HIR"你对天下无狗这招有了更深的了解。\n"NOR);
        }
        else
        {
                tell_object(me,HIR"你心烦意乱，费尽心神也难以领悟。\n"NOR);
        }
        me->add("qi",-100);
        me->add("jing",-100);
        me->add("neili",-100);
        me->add("jingli",-100);
        if (!wizardp(me)) me->start_busy(2+random(5));
	return 1;

}
