//Cracked by yujie
// /d/huanghe/obj/booktool.c

#include <localtime.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"�ķ��ı�"NOR, ({ "booktool", "sibao" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���Ƕ����˳��õ��ķ��ı�����ʹ����������赱���ְ��ֽ���д�ֵ�ʱ�⡣\n");
                set("value", 0);
                set("material", "mixed");
                set("no_drop", "�������㻹��ô����ѽ��\n");
                set("no_get", "���������������á�\n");
                set("no_steal", "���������͵������\n");
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
       return notify_fail( "��Ҫ��ʲô��\n" );
       
    if (query("owner")!=player->query("id"))
    {  write( "�ⲻ������ķ��ı����Ż�ԭ��ȥ�ɡ�\n");
       destruct(this_object());
       return 1;
    }
  
    if (player->query_busy() > 0) 
        return notify_fail("����æ���ء�\n");

    if (player->query("jingli") < 50)
        return notify_fail("����һ�¾����ٳ��ɡ�\n");

    message_vision("$N�ڹ�����ǰ���˸�λ�ӣ��ó��ķ��ı�׼��������\n",
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
    	case 0 : con=1;message_vision("$N�����������׷������Ҫ��ɵĹ�������\n",player);break;
    	
    	case 1 : con=1;message_vision("$N������һ������������ѵĲݸ忪ʼ����������\n", player);break;
    	
        case 2 : if (!random(3))
                 {      con=1;
                        message_vision("$N���ų��žͽ���Ѿ���ȫ���Եĳ�������ѧ�������ȥ�ˡ�\n",player);
                        if ((lev < 120) && random(2))
                        {	addlev=10*player->query("int");
                                player->improve_skill("literate",addlev);
                                write(HIW"�㲻֪���������������е����У�����д�ּ��ܴ�����ߡ�\n"NOR,player);
                                log_file("BangJob", sprintf("%s��%sʱ���챦������%s�����д��������\n",player->query("name"), ctime(time()), chinese_number(addlev)));
                        }        
                 }else
                 {	con=0;
                 	message_vision("$N���ų��ź�Ȼ�Ĳ�����������һ��С�ľ�Ȼ�����٣�������Ҫ���³����ˡ�\n",player);
                 }                 
                 break;
        
        case 3 : con=1;message_vision("$Næ���˰������ڳ����˺���һ�󱾣����˸�����׼�������ˡ�\n",player);break;
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
 message_vision("$N�����õ��ָ���ķ��ı������������ף��깤�뿪��������\n",player);
 if (present("bang ling",player))
 { 	ling=present("bang ling",player);
        bonus=10+random(20);
        
        addscore=ling->query("score")/10000;
        if (addscore>30) addscore=30;
        bonus = bonus + addscore;
        
        
        player->add("combat_exp",bonus*2);
        tell_object(player,HIW"����ι������õ�"+chinese_number(bonus)+"�㹦�͵㣬" + chinese_number(bonus*2)+ "�㾭��ֵ��\n"NOR);
        player->add("clbscore",bonus);
 	ling->delete("job");
 }
 player->receive_damage("jingli",40);
 destruct(this_object());
 return;
}
 



