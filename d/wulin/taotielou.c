//room: /d/wulin/taotielou.c
//piao 2001/10/17
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "饕餮楼");
        set("long", @LONG
这就是武林同盟中著名的饕餮楼。这里集天下美食，好酒于一地，武
林盟主经常在此宴请个各派高手。这里这里装饰的极为奢华，大理石的地
面，紫檀木的桌椅，墙上挂着珍贵的名家字画。你闻着诱人的香味，突然
间食指大动，不禁觉得肚子有些饿了。你可以向侍者要些酒菜（serve）。
楼上是有身份的人去的贵宾室。
LONG
        ); 
       
        set("exits",([
		"up":__DIR__"guibinshi",
        	"east":__DIR__"shangwu",
        ]));   

	set("objects",([
              __DIR__"npc/shizhe" : 1,
        ]));

                set("no_fight", "1");
                set("cost", 1);
                setup();
}
void init()
{
        add_action("do_serve", "serve");
}

int do_serve()
{
        object ob1, ob2, *inv, me = this_player();
        int food_ind, water_ind, f, w, i;
     
        inv = all_inventory(me);
        for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        food_ind = me->query("food");
        water_ind = me->query("water");

        if ( (int)me->max_food_capacity()-food_ind < 10
        && (int)me->max_water_capacity()-water_ind < 10 )
                return notify_fail("你已吃饱喝足，还是等会儿再要吧！\n");       

        message_vision("$N向侍者陪笑要些食物吃喝。\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f 
        && !present( "Fo tiao qiang", environment(me) ) )
        {
                ob1 = new("/clone/food/fotiao");
                ob1->move(me);
                message_vision("侍者笑呵呵地拿出"+ob1->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("侍者对$N说道：你不是有东西吃吗？吃完再说吧。\n", me); 
        else message_vision("侍者对$N说道：你别老想着吃，太饱可不好。\n", me);
        
        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w 

        && !present("tea", environment(me)) ) {
                ob2 = new("/d/huashan/obj/xiangcha");
                ob2->move(me);
                message_vision("侍者笑呵呵地拿出"+ob2->name()+"给$N。\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("侍者对$N说道：你不是有东西喝吗？喝完再说吧。\n", me);
        else message_vision("侍者对$N说道：你才刚喝过，怎么又渴啦？\n", me);

        return 1;
}





int valid_leave(object me, string dir)
{
        object *inv, ob1, ob2, ob3;
        string mengzhu, shangshan, fae;
        int i, f, w;
        inv = all_inventory(me);//传回me身上所有的物品
	
	if(!( ob1 = find_living("mengzhu")) )
        ob1 = load_object("/clone/npc/meng-zhu");
        mengzhu = ob1->query("winner");
        
        if(!( ob2 = find_living("shangshan")) )
        ob2 = load_object("/clone/npc/shang-shan");
        shangshan = ob2->query("winner");

        if(!( ob3 = find_living("fae")) )
        ob3 = load_object("/clone/npc/fa-e");
        fae = ob3->query("winner"); 
	
	if( dir == "up"&&!wizardp(me)) { 
        	if(!me->query_temp("guibinshi")
   		&& me->query("id") != mengzhu 
                && me->query("id") != shangshan 
                && me->query("id") != fae)
     		  	return notify_fail(CYN"侍者士拦住你，说道：楼上不是你能去的地方。\n"NOR);
        	
        }      
        for (i=0; i<sizeof(inv); i++) {  
                if (inv[i]->is_character())
                return notify_fail(CYN"侍者拦住你，说道：你不能带着其他玩家上去。\n"NOR);
		
        }         
		
	for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        if ( f>0 || w>0 ) return notify_fail("侍者拦着你说：别着急，还是把东西吃完再走吧。\n");
	
	return ::valid_leave(me, dir);
}
