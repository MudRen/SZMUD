// Code of ShenZhou
// ROOM/d/murong/chufang.c
// arthurgu 1999.9

inherit ROOM;

int serve();

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是慕容氏家的厨房，专为住在这里弟子门客提供伙食(serve)。
慕容氏先辈为皇室,所以即使是下人们的伙食，也极为精致。你可以
在这里大快朵颐。
LONG
        );

        set("exits", ([
                "east" : __DIR__"qing3",
        ]));
        
        setup();
}

void init()
{
       object ob=this_player();

        if (userp(ob) && !wizardp(ob) && ob->query("family/family_name") != "姑苏慕容") {
                message_vision("厨子喝道：“$N你不是我慕容家的人，怎么闯到这里来了？出去！\n",ob);
                remove_call_out("kickout");
                call_out("kickout", 1, ob);
        }

        add_action("do_serve", "serve");
}

int kickout(object ob)
{
        if (!present(ob,find_object("/d/murong/chufang.c"))) {
                return 1;
        }
        message_vision("厨子把$N赶了出去。\n",ob);
        ob->move("/d/murong/qing1");
        message("vision","只见，"+ob->query("name")+"满脸羞愧地从里面走了出来。\n", environment(ob), ob);
        return 1;
}

int do_serve()
{
        object ob,me;
        me=this_player();

        message_vision("$N向厨子要些食物吃喝。\n", me);

        if (!present("songzi gao", environment(me))
                && !present("feicui tianbing", environment(me))
                && !present("oufen", environment(me))
                && !present("songzi gao", me)
                && !present("feicui tianbing", me)
                && !present("oufen", me))
        {
                switch(random(3)) {
                case 0:
                        ob=new("/d/murong/obj/tianbing");
                        break;
                case 1:
                        ob=new("/d/murong/obj/gao");
                        break;
                case 2:
                        ob=new("/d/murong/obj/oufen");
                        break;
                }    
                ob->move(environment(me));
                message_vision("厨子端出"+ob->name()+"给$N。“您慢慢吃，不够还有。”\n", me);
        }
        else message_vision("厨子对$N说道：心这么黑，您还没吃完呢。\n", me);
        
        if (!present("biluochun", environment(me))
                && !present("ling1", environment(me))
                && !present("ling2", environment(me))
                && !present("biluochun", me)
                && !present("ling1", me)
                && !present("ling2", me)) {
                switch(random(3)) {
                case 0:
                        ob=new("/d/murong/obj/biluochun");
                        break;
                case 1:
                        ob=new("/d/murong/obj/ling1");
                        break;
                case 2:
                        ob=new("/d/murong/obj/ling2");
                        break;
                }
                ob->move(environment(me));
                message_vision("厨子端出"+ob->name()+"给$N。“您慢慢喝，不够还有。”\n", me);
        }
        else message_vision("厨子对$N说道：你还没喝完呢，喝完再说吧。\n", me);
        return 1;
}

int valid_leave(object me, string dir)
{
        if (present("songzi gao", me)
                || present("feicui tianbing", me)
                || present("oufen", me)
                || present("biluochun", me)
                || present("ling1", me)
                || present("ling2", me))
                return notify_fail("厨子拦着你说：“您还是吃完再走吧。”\n");
        return ::valid_leave(me, dir);
}
