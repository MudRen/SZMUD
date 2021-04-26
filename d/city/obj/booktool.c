//Cracked by yujie
// /d/huanghe/obj/booktool.c

#include <localtime.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"文房四宝"NOR, ({ "booktool", "sibao" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "副");
                set("long", "这是读书人常用的文房四宝，它使你回想起妈妈当年手把手教你写字的时光。\n");
                set("value", 0);
                set("material", "mixed");
                set("no_drop", "丢了他你还怎么工作呀。\n");
                set("no_get", "这样东西不能乱拿。\n");
                set("no_steal", "这个东西你偷不到。\n");
        }
        setup();
}

void init()
{
    add_action( "do_copy", "copy" );
    add_action( "do_copy", "chao" );
}

int do_copy(string arg)
{
    object player = this_player();
   

    if ((!arg)||(arg!="book"))
       return notify_fail( "你要抄什么？\n" );
       
    if (query("owner")!=player->query("id"))
    {  write( "这不是你的文房四宝，放回原处去吧。\n");
       destruct(this_object());
       return 1;
    }
  
    if (player->query_busy() > 0) 
        return notify_fail("你正忙着呢。\n");

    if (player->query("jingli") < 50)
        return notify_fail("振作一下精神再抄吧。\n");

    message_vision("$N在工作桌前找了个位子，拿出文房四宝准备工作。\n",
        player);
    player->start_busy(2);
    remove_call_out("copy_stages");
    call_out("copy_stages", 2, 0 , player);
    return 1;
}
int copy_stages(int stage, object player) 
{
    int lev , con=0 ,addlev;
    int i, k=0, neili, lvl, checking;
    lev = player->query_skill("literate", 1);

    if (stage < 0 || !objectp(player) ) return 1;
    switch (stage)
    {
    	case 0 : con=1;message_vision("$N认真聆听书僮分配今天要完成的工作任务。\n",player);break;
    	
    	case 1 : con=1;message_vision("$N深深吸一口气，翻开大堆的草稿开始抄了起来。\n", player);break;
    	
        case 2 : if (!random(3))
                 {      con=1;
                        message_vision("$N抄着抄着就渐入佳境，全心性的沉浸到文学的天地里去了。\n",player);
                        if ((lev < 120) && random(2))
                        {	addlev=10*player->query("int");
                                player->improve_skill("literate",addlev);
                                write(HIW"你不知不觉中领悟到了书中的真谛，读书写字技能大有提高。\n"NOR,player);
                                log_file("BangJob", sprintf("%s于%s时在天宝阁抄书获得%s点读书写字熟练度\n",player->query("name"), ctime(time()), chinese_number(addlev)));
                        }        
                 }else
                 {	con=0;
                 	message_vision("$N抄着抄着忽然心不在焉起来，一不小心竟然抄错不少，看来又要重新抄过了。\n",player);
                 }                 
                 break;
        
        case 3 : con=1;message_vision("$N忙活了半天终于抄完了厚厚的一大本，伸了个懒腰准备交工了。\n",player);break;
     }   
    
    if (stage==3) 
    {	player->start_busy(2);
        remove_call_out("do_end");
    	call_out("do_end",2,player);
    	return 1;
    }
    if (con==1) stage++;
    call_out("copy_stages", 10, stage, player);
    player->start_busy(10);
    
    return 1;
}

void do_end(object player)
{
 object ling;
 int bonus;
 int addscore;
 message_vision("$N将抄好的手稿和文房四宝都交还给书僮，完工离开了书桌。\n",player);
 if (present("bang ling",player))
 { 	ling=present("bang ling",player);
        bonus=10+random(20);
        
        addscore=ling->query("score")/10000;
        if (addscore>30) addscore=30;
        bonus = bonus + addscore;
        
        
        player->add("combat_exp",bonus*2);
        tell_object(player,HIW"你这次工作共得到"+chinese_number(bonus)+"点功劳点，" + chinese_number(bonus*2)+ "点经验值。\n"NOR);
        player->add("clbscore",bonus);
 	ling->delete("job");
 }
 player->receive_damage("jingli",40);
 destruct(this_object());
 return;
}
 



