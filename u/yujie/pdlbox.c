#include <ansi.h>
#include <localtime.h>

inherit ITEM;

void create()
{
        set_name(HIW"潘朵拉宝盒"NOR, ({ "box", "panduola baohe","baohe" }) );
        set_weight(10);
                set("unit", "个");
                set("long", "一个神秘的五彩盒子。\n传说中给人们带来幸运和厄运的魔力之盒。\n是不是经不起她的诱惑呢，那就快打开（open）他吧。。。\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n");
                set("no_get", "这样东西不能离开那儿。\n");
        
        setup();
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        int sel;

	object me = this_player();
	object gold;


        int rd;
        int i;
	rd = 5 + random(5);

        sel = random(14);
        if(arg!="box" && arg!="baohe" && arg!="panduola baohe")
                       return notify_fail("你要打开什么？\n");

	if(me->query("open_box") == 1)
	{	write(YEL"你想起上次打开宝盒的惊险，不由心中一颤，盒子扔在一旁不敢再次冒险。\n"NOR);
		destruct(this_object());
		return 1;
	}

        message_vision(HIW"$N满怀对幸运女神的期待打开了神秘的潘朵拉宝盒。\n\n"NOR,me);

        switch(sel)
	{
/*
		case 0 :
			write(HIG"你忽然感觉一阵酥麻，接着整个身体失去了知觉。。。。\n不一会，知觉又回到了你身上，但和以前的感觉不一样，仿佛脱胎换骨一般。\n"NOR);
			me->add("con",1);
			me->add("dex",1);
			break;
		
*/
		case 1 :
			message_vision(HIC"盒盖一起，周围的空气忽然一阵波动，一股强大的类似气流的不知名物体溜入了$N体内。\n"NOR,me);
			write(HIG"一股莫名的力量注入了你的体内，顿时你感觉自己的内力修为提升了不少。\n"NOR);
			me->add("max_neili",50+random(50));
			break;

		case 2 :
                        tell_object(environment(me),HIC"一阵天籁之音伴随盒子打开而飘扬出来，顿时周围一片庄严详和之气。\n"NOR);
			write(HIG"这股震人心衔的声音让你感到一种前所未有的明悟。。。。忽然间你好象明白了很多以前不明白的东西。\n"NOR);
			for(i=0;i<rd;i++)
                                me->improve_skill("literate",20000);
			break;

		case 3 :
                        tell_object(environment(me),HIY"盒子发出一阵轰隆的响声，眼前金光一闪，出现一大堆黄金。\n"NOR);
			write("还不赶快捡起来藏好。\n");
			gold = new("/clone/money/gold");
			gold->set_amount(50+random(50));			
			gold->move(environment(me));
			break;

		case 4 :
			message_vision(HIR"只见一道红光冲天而出，唰的一声来到$N的手中，原来是一把浴火的宝剑。\n"NOR,me);
			gold = new(__DIR__"obj/huoshen");
			gold->move(me);
			break;

		case 5 :
			message_vision(HIW"只见一道银白的光芒冲天而出，唰的一声来到$N的手中，原来是一把银色的宝剑。\n"NOR,me);
			gold = new(__DIR__"obj/xianzhi");
			gold->move(me);
			break;
		
		case 6 :
			message_vision(HIY"$N从盒子里拿出一根刚烧烤出炉的牛肉串，浓浓的香味传出顿时让周围的人流了一地的口水。\n"NOR,me);	
			gold = new(__DIR__"obj/rouchuan");
			gold->move(me);
			break;

		case 7 :
			message_vision(YEL"伴随一阵时空的扭曲，一只西域特产的纯种白骆驼出现在$N的眼前。\n"NOR,me);	
			gold=new("/clone/horse/btcamel");
        		gold->move(environment(me));
       			gold->set_lord(me);
		        gold->set_leader(me);
        		break;

		case 8 :
                        message_vision(BLU"一阵象来自地狱的幽怨的声音从盒中飘出，顿时$N的心神被夺，好象失忆的游魂一般。\n"NOR,me);
			write("你感觉自己的内力修为略有受损。\n");
                        if( me->query("max_neili") > 50)
                        me->add("max_neili",-10-random(5));
			break;
		case 9 :
                        tell_object(environment(me),YEL"一阵时空的扭曲过后，忽然面前出现了一只凶猛的老虎。\n"NOR);   
			gold = new("/d/city/npc/laohu");
			gold->move(environment(me));
			break;

		case 10 :
                        tell_object(environment(me),HIW"一阵时空的扭曲过后，忽然面前出现了一只西域特产的灵蛇。\n"NOR);       
			gold = new("/d/xingxiu/npc/lingshe.c");
			gold->move(environment(me));
			break;

		case 11 :
                        message_vision(BLU"盒子里飘出一阵令人战栗的阴风，顿时一阵虚弱和无助的感觉涌向$N。\n"NOR,me);
			me->add_temp("apply/dexerity", -10);
        		me->add_temp("apply/attack", -10);
			break;

		case 12 :
                        message_vision(BLU"一阵象来自地狱的幽怨的声音从盒中飘出，顿时$N的心神被夺，好象失忆的游魂一般。\n"NOR,me);
			write("你感觉自己的读书写字技能微有受损。\n");
			i=me->query_skill("literate");
			i=i*2-1-random(2);
			break;

		default:
                	message_vision(HIW"砰的一声掀开盒子后，却发现里面什么也没有，$N失望极了。\n"NOR,me);	
			break;
                
        	}
		me->set("open_box",1);
		destruct(this_object());
		return 1;
		
}

			
