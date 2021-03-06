// Code of ShenZhou
//ROOM: /d/murong/humian
//arthurgu 1999.9

inherit ROOM;
string look_zhuang();
void init();

void create()
{       set("short", "湖面");
        set("long", @LONG
    湖面光滑如镜，仔细看去，水面下隐隐约约立着些
不规则的木桩(zhuang)，看来慕容氏弟子经常在这里练
习轻功。
LONG  
    );           
  
        set("outdoors", "murong");

	set("exits", ([ 
        "northwest" : __DIR__"lianwu",
                     ]));

        set("item_desc",([
                         "zhuang" : ( :look_zhuang:),                        ]));
        setup();
       }
 
string look_zhuang()
{ return "一根根木桩深埋于湖底，湖面上只隐隐约约露出\n"
        "一些端倪。你不知道这些木桩通往何处，如果上去\n"
       "的话，不知道结果怎样。\n";}

void init()
{
       object ob=this_player();

        if (userp(ob) && !wizardp(ob) && ob->query("family/family_name") != "姑苏慕容") {
                message_vision("门客喝道：“$N你不是我慕容家的人，怎么闯到这里来了？出去！\n",ob);
                remove_call_out("kickout");
                call_out("kickout", 1, ob);
        }

        add_action("do_go", "go");
}

int kickout(object ob)
{
        if (!present(ob,find_object("/d/murong/chufang.c"))) {
                return 1;
        }
        message_vision("门客把$N赶了出去。\n",ob);
        ob->move("/d/murong/qing1");
        message("vision","只见，"+ob->query("name")+"满脸羞愧地从里面走了出来。\n", environment(ob), ob);
        return 1;
}


int do_go(string arg)
{
        object me;
        me = this_player () ;

       if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("什么？\n");
   
        if ( (int)me->query("neili") < 80)
        return notify_fail ("$N伸脚轻轻试了试木桩，心中有点发慌，忙缩了回来。\n");

         if ( (int)me->query("combat_exp") <10000)
        {
        me->receive_damage("qi", 50, "掉进湖里淹死了");
                me->receive_wound("qi",  50, "掉进湖里淹死了");
                message_vision("$N只觉得脚下一个踉跄，... 
啊...！\n", me);
                tell_object(me, 
"你掉进大湖，几经努力才爬上木桩，身上又疼又酸。\n");
                message("vision", "只见" + me->query("name") + 
"从湖里湿漉漉爬上来，脸色苍白已极！\n", environment(me), me);
          return 1;
        }

         me->add("jingli", (-1)*random(50), "淹死了");
         me->add("neili", (-1)*random(50));
               
        message_vision("$N脚踩八卦方位，走得飞快。\n", me);

     if ( (int)me->query_skill("dodge", 1) >= 120)
       { me ->move("/d/murong/mantuo1");
       tell_object(me, "\n你健步如飞，不一会就走到曼陀山庄...\n\n" ) ;
        return 1 ;
        }
    else if ( (int)me->query_skill("dodge", 1) < 120)
        me->improve_skill("dodge", me->query("dex")); 
        write("你走了一会儿木桩，感到腿脚有点酸痛。\n");                      
       return 1;
}
 


 
