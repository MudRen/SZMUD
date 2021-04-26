// kunlun pianting
// by earl
inherit ROOM;
void create()
{
    set("short", "pianting");
    set("long",@LONG
这是个偏厅,正前方的墙上有一石龙，栩栩如生。龙角，龙头,特别是石龙的一双眼睛在黑暗中闪闪发光好想是一对宝石,不知道有什么机关.
LONG
);
        set("exits", ([
                "east" :__DIR__"luange",
]));
    set("qiao",1);
    setup();
}
void init()
{
        add_action("do_look","look");
        add_action("do_climb","climb");
        add_action("do_qiao","qiao");
        add_action("do_jump","jump");
}
int do_look(string arg)
{
        object me=this_player();
        if (!arg)       return 0;
//        if (!me->query_temp("killer")) return 0;
//          if (!me->query_temp("climb")) return 0;
        switch (arg){
                case "龙头":    if (query("qiao"))
                                write("细看这个龙头，两眼炯炯有神，似乎有些异处。\n");
                                else
                                write("细看这个龙头，才发现龙头少了两个龙珠子。\n");
                        return 1;
                case "石门":    write("石门上有两个门环，却看不到一丝缝隙，门环上有\n两个洞，不知道是做什么用的。\n");
                        me->set_temp("look",1); 
                return 1;
        }
        return 0;
}
int do_climb(string arg)
{
        object me=this_player();
        object weapon;
        if(!arg)        return 0;
          if(!me->query_temp("look")) return 0;
        if(arg != "龙角")       return notify_fail("你要往那爬呀？\n");
        if(me->query_temp("chan")) return notify_fail("你已经在龙头上了。\n");
        if (!objectp(weapon = me->query_temp("weapon"))) return notify_fail("这里光溜溜的，你怎么爬呀。\n");
        if (weapon->query("skill_type")!="whip")        return notify_fail("你还是找条绳子什么的，也许会爬得上去哦。\n");
        message_vision("$N使出"+weapon->query("name")+"，往上一抛，缠在龙角上。\n然后$N施展轻功，爬到了龙头上。\n",me);
        me->set_temp("chan",1);
                return 1;
}
int do_qiao(string arg)
{
        object me=this_player();
        object weapon,ob;
        if(!arg)        return 0;
        if(!me->query_temp("chan")) return notify_fail("你够不着。\n");
        if(!query("qiao")) return notify_fail("你还要橇什么？\n");
        if(arg != "龙眼")       return notify_fail("你想撬什么嘛？\n");
        if (!objectp(weapon = me->query_temp("weapon"))) return notify_fail("用手啊，也许找些什么工具来会好点哦。\n");
         if (weapon->query("skill_type")!="sword")      return notify_fail("你举起手中"+weapon->query("name")+"挥舞了几下，才发现这样东西不好使也。\n");
        message_vision("$N掏出一把"+weapon->query("name")+",使劲地撬了起来。\n$N连吃奶的力气都用上了，终于撬起了两个硕大的龙眼。\n",me);
         ob=new(__DIR__"obj/lzhu.c");
        if (!ob->move(me))
                ob->move(this_object());
         ob=new(__DIR__"obj/lzhu.c");
        if (!ob->move(me))
                ob->move(this_object());
        set("qiao",0);
        return 1;
}
int do_jump(string arg)
{
        object me=this_player();
        if(!arg)        return 0;
        if(!me->query_temp("chan")) return 0;
        message_vision("$N一个纵身，跳了下了来。\n",me);
        me->delete_temp("chan");
        return 1;
}
void open_door(object ob,int i)
{
    object room;
    if (!ob || environment(ob)!=this_object())  return;
    if (i<10)
    {
    tell_room(this_object(),"石门激烈地震动了一下，“咯...咯...咯...”\n");
    call_out("open_door",10,ob,i+1);
    return;
    }
    tell_room(this_object(),"门上的石环转动了一圈，只见石门猛地向两边分开。");
    if (!room=find_object(__DIR__"lwshi"))
        room=load_object(__DIR__"lwshi");
    message_vision("$N站立不稳，被一股强大的吸力拉了进去。\n",ob);
    ob->move(room);
    ob->unconcious();
}
