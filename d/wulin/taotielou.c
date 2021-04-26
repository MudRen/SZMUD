//room: /d/wulin/taotielou.c
//piao 2001/10/17
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����¥");
        set("long", @LONG
���������ͬ��������������¥�����Ｏ������ʳ���þ���һ�أ���
�����������ڴ���������ɸ��֡���������װ�εļ�Ϊ�ݻ�������ʯ�ĵ�
�棬��̴ľ�����Σ�ǽ�Ϲ������������ֻ������������˵���ζ��ͻȻ
��ʳָ�󶯣��������ö�����Щ���ˡ������������ҪЩ�Ʋˣ�serve����
¥��������ݵ���ȥ�Ĺ���ҡ�
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
                return notify_fail("���ѳԱ����㣬���ǵȻ����Ҫ�ɣ�\n");       

        message_vision("$N��������ЦҪЩʳ��Ժȡ�\n", me);

        if ( (int)me->max_food_capacity()-food_ind >= 40 && !f 
        && !present( "Fo tiao qiang", environment(me) ) )
        {
                ob1 = new("/clone/food/fotiao");
                ob1->move(me);
                message_vision("����Ц�Ǻǵ��ó�"+ob1->name()+"��$N��\n", me);
        }
        else if ( (int)me->max_food_capacity()-food_ind >= 40 )
                message_vision("���߶�$N˵�����㲻���ж������𣿳�����˵�ɡ�\n", me); 
        else message_vision("���߶�$N˵������������ųԣ�̫���ɲ��á�\n", me);
        
        if ( (int)me->max_water_capacity()-water_ind >= 40 && !w 

        && !present("tea", environment(me)) ) {
                ob2 = new("/d/huashan/obj/xiangcha");
                ob2->move(me);
                message_vision("����Ц�Ǻǵ��ó�"+ob2->name()+"��$N��\n", me);
        }
        else if ( (int)me->max_water_capacity()-water_ind >= 40 )
                message_vision("���߶�$N˵�����㲻���ж������𣿺�����˵�ɡ�\n", me);
        else message_vision("���߶�$N˵������Ÿպȹ�����ô�ֿ�����\n", me);

        return 1;
}





int valid_leave(object me, string dir)
{
        object *inv, ob1, ob2, ob3;
        string mengzhu, shangshan, fae;
        int i, f, w;
        inv = all_inventory(me);//����me�������е���Ʒ
	
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
     		  	return notify_fail(CYN"����ʿ��ס�㣬˵����¥�ϲ�������ȥ�ĵط���\n"NOR);
        	
        }      
        for (i=0; i<sizeof(inv); i++) {  
                if (inv[i]->is_character())
                return notify_fail(CYN"������ס�㣬˵�����㲻�ܴ������������ȥ��\n"NOR);
		
        }         
		
	for (i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("food_supply") && inv[i]->value() >= 0) f++;
                if (inv[i]->query("drink_supply") && inv[i]->value() >= 0) w++;
        }

        if ( f>0 || w>0 ) return notify_fail("����������˵�����ż������ǰѶ����������߰ɡ�\n");
	
	return ::valid_leave(me, dir);
}
