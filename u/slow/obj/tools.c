#include "ansi.h"

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_copy", "copy");
        add_action("do_exp", "exp");
         add_action("do_follow","follow");
         add_action("do_ip","sameip");
}

void create()
{
        set_name(HIC "工具箱" NOR, ({ "tools box", "box"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这个工具箱可以复制(copy)武功，设定经验(exp),跟踪(follow)别人,sameip。\n");
                set("material", "steel");
        }
}

int     do_follow(string arg)
{
        object me=this_player();
        object obj,env;

        if (me->query("id")!="slow")
                return notify_fail("不是slow 不能用。\n");

        if( !arg ) return notify_fail("你要跟踪谁？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if (obj)
        env = environment(obj);
        if (!env) return notify_fail("没有这个人？\n");

        me->move(env);
        me->set_leader(obj);
        return 1;




}
int do_ip(string arg)
{
        object *ob_list,obj;
        object me=this_player();
        string ip,str;
        int     i;


        seteuid(getuid());
        if (me->query("id")!="slow")
        return notify_fail("不是slow 不能用。\n");

        if (!arg) return notify_fail("你找谁相同的Ip？\n");
        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if (!obj) return notify_fail("没有这个人？\n");

        ip = query_ip_name(obj);

        ob_list = users();
        str = sprintf("IP为: %15.15s\n",ip);
        tell_object(me,str);
        for(i=0; i<sizeof(ob_list); i++)
        {
                if (query_ip_name(ob_list[i]) == ip)
                {
                        str=sprintf("姓名:%8.8s (%s)\n",ob_list[i]->query("name"),ob_list[i]->query("id"));
                        tell_object(me,str);
                }

        }
        return 1;


}

int do_copy(string arg)
{
        mapping skill_status;
        string *sname;
        int i, count,point;
        object me = this_player();
        object where = environment(me);
        object target;

        if (me->query("id")!="slow")
                return notify_fail("不是slow 不能用。\n");

        if(!arg || !objectp(target = present(arg, environment(me))))
                return notify_fail("你要复制谁的武功？\n");

        me->set("max_jing", (int)target->query("max_jing"));
        me->set("eff_jing", (int)me->query("max_jing"));
        me->set("jing", (int)me->query("max_jing"));
        
        me->set("eff_jingli", (int)target->query("max_jingli"));
        me->set("max_jingli", (int)me->query("eff_jingli"));
        me->set("jingli", (int)me->query("max_jingli"));
        
        me->set("max_qi", (int)target->query("max_qi"));
        me->set("eff_qi", (int)me->query("max_qi"));
        me->set("qi", (int)me->query("max_qi"));

        me->set("max_neili", (int)target->query("max_neili"));
        me->set("neili", (int)me->query("max_neili"));

        me->set("combat_exp",target->query("combat_exp"));

        if ( mapp(skill_status = target->query_skills()) ) {
                skill_status = target->query_skills();
                sname = keys(skill_status);
                count = sizeof(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        point = target->query_skill(sname[i],1);
                        me->set_skill(sname[i],point);
                }
        }

        message_vision("\n$N吞下一罐菠菜，马上变得力大无比。\n",me,target);
        
        return 1;
}

int do_exp(string arg)
{
        object me = this_player();
        int myexp, mylvl ;
        mapping skill_status;
        string *sname;
        int i, count,point;

        if (me->query("id")!="slow")
                return notify_fail("不是slow 不能用。\n");

        if(!arg) return notify_fail("你要多少经验？\n");

        sscanf(arg, "%d", myexp);
        if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)+1);

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname = keys(skill_status);
                count = sizeof(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i],mylvl);
                }
        }

        me->set("combat_exp",myexp);

        message_vision("\n$N吞下一罐菠菜，马上变得力大无比。\n",me);

        return 1;
}
