// Code of ShenZhou
inherit ROOM;

int do_exercise(string);

void create()
{
        set("short", "马厂");
        set("long", @LONG
你的面前是一大片绿油油的草坪，抬眼望去，可以看到几个在远
方溜马的身影。近出散散落落的几匹野马(horse)正在吃草。
LONG
        );
        set("outdoors", "dali");

        set("item_desc", ([
                "horse" :
"这是准备用来做军马的，一个个生的身高体大，看起来一付野性难驯的样子。\n"

])  ) ;

        set("objects", ([
                "/d/dali/npc/mafu" : 1,
]));
        set("cost", 3);
        setup();
}

void init()
{
        add_action("do_exercise", "exercise");
}

int do_exercise(string arg)

{
        object me = this_player();

if ( me->query("job/description") == "大理平南王府马夫" )
 
        {
                tell_object(me, "你还是专心溜马吧！\n");
                return 1;
        }
        
        return 0;
}


int valid_leave(object me, string dir)
{
        mapping myfam;

        myfam = (mapping)me->query("family");

        if ( (string)me->query("job/description") == "大理平南王府马夫" )
        if (objectp(present("ma fu", environment(me))))
return notify_fail("马夫喝道：马还满身贼膘，你就想溜！\n");        
else            
        {
                message_vision("$N看马夫不在，趁机溜走了。\n", 
me);         

                me->delete_temp("apply/short");
                me->add("job/fail", 1);
                me->delete("job/supervisor");
                me->delete("job/description");
                me->delete("job/object");
        }
        

        
        return ::valid_leave(me, dir);
}


