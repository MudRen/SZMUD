inherit ITEM;
#include "/clone/misc/site.h"
#include <ansi.h>
string look_map();
void create()
{
        set_name(HIW"乾坤地图"NOR, ({ "newbie maps","trans map", "qkdt", "maps", "ditu"}) );
        set_weight(500);
        set("no_drop","这可是你吃饭的家伙，怎么能扔呢？\n");
        set("no_get", 1);  
        set("no_steal", 1);  
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "\n这是一张【 神州 】的地图，专供新手使用。\n你现在可以在它的引导下("HIW"trans"NOR")到达一些有用的区域("HIW"look area"NOR")。\n如果你饿了，可以咬("HIW"full"NOR")一口这张地图补充食物和饮水。\n要是你还有其他不明白的，请输入 newbie 命令("HIW"newbie"NOR")。\n");
                set("unit", "张");
        }
        setup();
}
void init()
{
        object me = this_player();
        if ( !me->is_ghost() ) {
        add_action("do_look","look");
        add_action("do_trans","trans");
        add_action("do_full","full");
        }
}
int do_trans(string arg)
{
        object me,room,ob,*obj;
        string msg;
        int i;
        me=this_player();
        
        if( ! environment()->is_character() ) return 0;
        if (me->query("job/description") == "守卫山门" && objectp(present("zhike daozhang", environment(me))))
               return notify_fail(HIG"\n你不想做这份工了吗？如果不想做了就先放弃吧！\n"NOR);

        if (me->query("age") >= 18)
                return notify_fail("都这么大了还不认识路？\n");

        if (me->query("combat_exp") >= 40000)
                return notify_fail("江湖经验也不少了，还不认识路？\n");
                
        if( !arg ) return notify_fail("你要去哪里？\n");
        
        if (me->is_fighting())
                return notify_fail("想这么走，没那么容易吧！\n");

        if  (!environment(me)->query("outdoors"))
                return notify_fail("房间里怎么找方向？到大街上去试试吧。\n");

/*      if ( me->query("family/family_name"))
        {
                if (arg != mp[me->query("family/family_name")]["ID"] && !stringp(city[arg]))
                        return notify_fail("你要去哪里？\n");               
        }else */
        if (!stringp(places[arg]))
                return notify_fail("你要去哪里？\n");

        ob=first_inventory(me);

        while(ob){
        if (ob->is_character() && !ob->is_corpse() )
                return notify_fail("你不能带"+ob->name()+"和你一起走！\n");
        ob=next_inventory(ob);
        }
        if( stringp(msg = me->query("env/msg_mout")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision("\n匆匆忙忙地跑过来一个新手帮助精灵。\n"CYN"新手帮助精灵一把抓住$N的手，一转眼便不见了。\n\n"NOR, me);
        if (!room=find_object(places[arg]) )
                room=load_object(places[arg]);
        me->move(room);
        if( stringp(msg = me->query("env/msg_min")) )
                {if (msg!="") message_vision(msg+"\n", me);}
        else
                message_vision(CYN"\n新手帮助精灵对$N说，你想到的就是这里吧？以后要记得路哦。\n"NOR"新手帮助精灵说完，便急匆匆地离开了。\n\n", me);

        me->receive_damage("jingli", 10);
                if(me->query("potential") > 10) me->add("potential", -random(3)); 
                else me->receive_damage("jing", 10);
        return 1;
}
int do_full()
{
        int max;
        object me = this_player(); 

        if (me->query("age") >= 16)
                return notify_fail("你怎么还像小孩子一样？\n");

        if (me->query("combat_exp") >= 6000)
                return notify_fail("你现在应该可以自立了。\n");

        if (me->query("food") < me->max_food_capacity() / 3
            || me->query("water") < me->max_water_capacity() / 3)
        {
                max = me->max_food_capacity();
                me->set("food",max);
                max = me->max_water_capacity();  
                me->set("water",max);
                tell_object(me,RED"你张起大嘴，咬了几口地图的边角，顿时感觉好多了！\n"NOR);
                return 1;
        }else{
                tell_object(me,CYN"你现在不是很饿，留着这张地图慢慢吃吧！\n"NOR);
                return 1;
        }
}
int do_look(string arg)
{
        object me = this_player();
        object ob = this_object();
        string mpn, msg = "";
        string *cityx, *mpx;
        int i, cnt = 0;
        mpn = me->query("family/family_name");

        if (!arg || arg != "area")return 0;
        if (me && present(ob, me))
        {
/*              if (me->query("family/family_name"))
                {
                        msg += "\n你现在可以在它的引导下(trans)到达一些地方：\n\n     ";
                        cityx = keys(city);
                        for (i=0; i<sizeof(cityx); i++) {
                                msg = sprintf("%s"HIM"%-2s"NOR" : "HIG"%-12s"NOR"%s", msg, cityx[i], city[cityx[i]], (cnt%3==2? "\n     ": ""));
                                cnt ++;
                        }
                        if (mpn != "大理段家")
                                msg += HIY+mp[mpn]["ID"]+NOR+" : "+HIC+mp[mpn]["NAME"]+NOR;
                }else{*/
                        msg += "\n你可以在它的引导下(trans)到达一些地方：\n\n     ";
                        cityx = keys(city);
                        for (i=0; i<sizeof(cityx); i++) {
                                msg = sprintf("%s"HIM"%-2s"NOR" : "HIG"%-12s"NOR"%s", msg, cityx[i], city[cityx[i]], (cnt%3==2? "\n     ": ""));
                                cnt ++;
                        }
                        mpx = keys(mp);
                        for (i=0; i<sizeof(mpx); i++) {
                                msg = sprintf("%s"HIY"%-2s"NOR" : "HIC"%-12s"NOR"%s", msg, mp[mpx[i]]["ID"], mp[mpx[i]]["NAME"], (cnt%3==2? "\n     ": ""));
                                cnt ++;
                        }
//              }
        }
        tell_object(me,msg+"\n");
        return 1;
}
void owner_is_killed() { destruct(this_object()); }
