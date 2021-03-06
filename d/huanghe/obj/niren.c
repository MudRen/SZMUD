/* /d/huanghe/obj/niren.c
** 十八泥人 
** created by yujie 
** created in 1/2002 
*/ 

#include <ansi.h> 
  
inherit ITEM; 

      
void create() 
{ 
	set_name(CYN"泥人玩偶"NOR, ({ "niren wanou", "niren" }) ); 
	set_weight(10); 
	set("unit", "套"); 
	set("long", "这是一套泥制的玩偶。\n放在木盒里，盒中垫着棉花，并列着三排泥人。\n每排六个，共是一十八个。\n玩偶制作精巧，每个都是裸体的男人，皮肤上涂了白垩，画满了一条条红线，更有无数黑点，都是脉络和穴道的方位。\n"); 
	set("value", 0); 
	set("material", "wood"); 
	set("no_drop", "这样贵重的东西怎么能随便乱丢呢。\n"); 
	set("no_get", "这样东西不能离开那儿。\n"); 
	set("broken",0);

	setup();
}

void init()
{
	add_action("do_break","break");
}

int do_break(string arg)
{	
	object me=this_player();
	object ob=this_object();
	
	if (arg != "niren wanou" && arg != "niren")
		return notify_fail("你要捏碎什么？\n");
		
	if ( query("broken")==1 )	
		return notify_fail("这套泥人已经被捏碎过了。\n");
		
	message_vision(HIW"$N运劲对着泥人一捏。。。\n"NOR+HIG"只见刷刷刷几声，裹在泥人外面的粉饰、油彩和泥底纷纷掉落。\n随着泥粉褪落，里面露出一层油漆的木面。\n$N索性再将泥粉剥落一些，里面依稀现出人形，当下$N将所有泥人身上泥粉尽数剥去，露出一个个裸体的木偶来。\n木偶们神情或喜悦不禁，或痛哭流泪，或裂觜大怒，或慈和可亲，无一相同。\n木偶身上的运功线路，也与泥人身上所绘全然有异。\n"NOR,me);

	set("broken",1);
	set_name(YEL"木偶"NOR, ({ "mu ou", "muou" }) ); 
	set("long","这是一套泥人中藏着的木偶。\n它们身上油着一层桐油，绘满了黑线，却无穴道位置。\n木偶刻工精巧，面目栩栩如生，张嘴作大笑之状，双手捧腹，神态滑稽之极，相貌和本来的泥人截然不同。\n木偶上面绘制的运功线路看起来很奇妙，可以尝试照它们身上的线路练练功（liangong）看。\n");
		
	add_action("do_liangong","liangong");
	return 1;
}

int do_liangong(string arg)
{
	object me=this_player();
	object ob=this_object();
	int step=0;
	
        if(me->is_busy() )
		return notify_fail("你正忙着呢。\n"); 

	if ( me->query("neili")<1000)
		return notify_fail("你体内真气不足，无法按照所绘线路运气练功。\n");
		
        if ( me->query_skill("force",1) > 299)
		return notify_fail("你的内功已有大成，不需要再按照木偶上的方式进行修炼了。\n");
		
        message_vision("$N当下盘膝坐定，将木偶放在面前，丹田中微微运气，便有一股暖洋洋的内息缓缓上升。\n$N依着木偶身上所绘线路，引导内息通向各处穴道。\n",me);
	
	remove_call_out("doing");
          call_out("doing", 10, 0 , me); 
	me->start_busy(10);
	return 1;
}

int doing(int step, object me)
{
        switch (step)
	{
        case 0 : message_vision("$N体内真气水火相济，阴阳调合，已然十分深厚，将这股内力依照木罗汉身上线路运行，一切窒滞处无不豁然而解。\n",me);break;
	case 1 :
                message_vision("$N照着线路运行三遍，然后闭起眼睛，不看木偶而运功，只觉舒畅之极，接着又换了一个木偶练功。\n",me);
		break;
    
    	case 2 :
                message_vision("$N全心全意的沉浸其中，练完一个木偶，又是一个，于外界事物，全然的不闻不见。\n",me);
		break;
		
	case 3 :
                message_vision("$N练完了所有十八尊木罗汉身上所绘的线路，长长的舒了口气，将木偶放入盒中，合上盒盖，只觉神清气爽，内力运转，无不如意，\n",me);
                me->improve_skill( "force",me->query("con")*60 ); 
                me->add("neili",-500-random(300)); 
		break;
	}
	
        if ( step < 3)
	{	step++;
		remove_call_out("doing");
		call_out("doing",10,step,me);
		me->start_busy(10);
	}
	
        return 1;
}
		

