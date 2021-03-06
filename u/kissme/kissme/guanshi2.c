

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();

mapping *changxi = ({ 
         ([ "changxi":"扬州","where":"city"   ]),
         ([ "changxi":"泉州","where":"quanzhou"]),   
                   });
mapping query_changxi()
{
        return changxi[random(sizeof(changxi))];
}

void create()
{
        set_name("管事", ({"guan shi", "guan", "guanshi"}));
        set("gender", "男性");
        set("age", 35);
        set("title", HIW"钦定民间曲艺事务"NOR);
        set("long", 
                "他是北京大戏院的管事，朝廷委派他管理民间的一切杂耍卖艺表演。\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "工作" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
                "完成" : (: ask_done    :),
                "报酬" : (: ask_done    :),
        ]) );

        setup();
        carry_object("clone/armor/cloth")->wear();
}
int do_gongzuo()
{      
        mapping changxi,changxiwhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")>0)
    {
                tell_object(me,CYN"管事向你喉道：磨蹭什么？还不快去！\n"NOR);
                return 1;
    } 
    else 
    if( me->query("combat_exp")>100000)
    {
                tell_object(me,"管事说道：你已经不是小孩子了，该去做些正经工作了。\n");
                return 1;
    }
    changxi = this_object()->query_changxi();
    changxiwhere = changxi["where"];
    message_vision(CYN"管事对$N说道：你快去" + changxi["changxi"] + "附近的街道上表演一下吧。\n"NOR,me); 
    message_vision("管事吩咐手下给了$N一套"CYN"表演道具"NOR"。\n",me); 
    
        me->set_temp("obj/changxi", 1);
        me->set_temp("obj/where",changxiwhere);
        ob=new(__DIR__ "daoju");
        ob->move(me);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/changxi")< 1)
    {
                tell_object(me,"没干活就像要报酬？快滚，小心我报官抓你！\n");
                return 1;
    } 
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"你还没表演，就来交差？想死是不是？\n");
                return 1;
    }
    message_vision(CYN"管事对$N说道：哦，用完了？那就把东西还给我吧。\n"NOR,me); 
    me->delete_temp("obj");
    
    if (ob = present("changxi daoju", this_player()))
    {
       message_vision("管事吩咐仆人把表演道具收回去了。\n",me);
       destruct(ob);
       return 1;
    }
    return 1;
}