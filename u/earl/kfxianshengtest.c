

#include <ansi.h>
#include <command.h>
inherit NPC;
void consider();
int do_gongzuo();
int ask_done();

mapping *chuaimo = ({ 
         ([ "chuaimo":"杭州西湖","where":"hangzhou"   ]),
         ([ "chuaimo":"武当山","where":"wudang"   ]),
         ([ "chuaimo":"西夏国","where":"xixia"]),   
       ([ "chuaimo":"华山","where":"huashan"]),  
         ([ "chuaimo":"云南大理","where":"dali"]),   
         ([ "chuaimo":"天山","where":"tianshan"]),   
         ([ "chuaimo":"终南山","where":"zhongnan"]),   
         ([ "chuaimo":"福建泉州","where":"quanzhou"]),   
                   });
mapping query_chuaimo()
{
        return chuaimo[random(sizeof(chuaimo))];
}

void create()
{
        set_name("库房先生", ({"kufang xiansheng", "kufang", "xiansheng"}));
        set("gender", "男性");
        set("age", 55);
        set("title", "昆仑派内务总管");
        set("long", 
                "他是昆仑派掌管库房的老先生。为传播何足道的圣名，他常给小孩子工具以助他们研习琴画技艺。\n");
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
        mapping chuaimo,chuaimowhere;
        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/chuaimo")>0)
    {
                tell_object(me,CYN"库房先生停了一下又说：要是完成了工作，就回复我"HIW"ask xiansheng about 完成"CYN"了。\n"NOR);
                return 1;
    } 
    else 
      if( me->query("combat_exp")>2000000)
    {
                      tell_object(me,"库房先生说道：你已经不是小孩子了，该去做些正经工作了。\n"); 
                return 1;
    }

    else
        if(me->query("family/family_name")!="昆仑派" && me->query("combat_exp")>=100000)
        {
               message_vision("管事先生赶紧对$N作了一揖，道：这种小事怎么敢劳驾您呢!\n",me);
        return 1;
        }
    chuaimo = this_object()->query_chuaimo();
    chuaimowhere = chuaimo["where"];
    message_vision(CYN"库房先生对$N说道：你快去" + chuaimo["chuaimo"] + "附近转悠一下吧。\n找个风景好的地方，可以有助你揣摩技艺。\n"NOR,me); 
    message_vision("库房先生给了$N一套"HIW"琴画行囊"NOR"。\n",me); 
    
        me->set_temp("obj/chuaimo", 1);
        me->set_temp("obj/where",chuaimowhere);
            ob=new(__DIR__"xingnang");
        ob->move(me);
        return 1;   
}

int ask_done()
{      

        object me,ob;
        me = this_player(); 
        
    if( me->query_temp("obj/chuaimo")< 1)
    {
                tell_object(me,"库房先生给过你任务吗？\n");
                return 1;
    } 
    if( me->query_temp("obj/done")< 1)
    {
                tell_object(me,"你今天瞎晃荡了一天，技艺没有长进吧？\n");
                return 1;
    }
    message_vision(CYN"库房先生对$N说道：哦，用完了？那就把东西还给我吧。\n"NOR,me); 
    me->delete_temp("obj");
    me->add("combat_exp",me->query("kunlun/jlexp"));
    me->add("potential",75+random(60));
    if( me->query("potential") > me->query("max_potential") ) me->set("potential",me->query("max_potential") ); 
    

        me->improve_skill("qinqi-shuhua",200 + me->query_skill("literate", 1)*3/4);
    
      if (ob = present("xingnang", this_player()))
    {
       message_vision("库房先生把"HIW"琴画行囊"NOR"收回去了。\n",me);
       destruct(ob);
    }
    return 1;
}
