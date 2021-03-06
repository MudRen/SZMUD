#include <command.h>;
#include <ansi.h>;
inherit ROOM;

mapping family = ([
        "少林寺"   : ({ "/d/shaolin/zoulang1","/d/shaolin/hsyuan1",
                       "/d/shaolin/luohan1","/d/shaolin/luohan5", }),
        "武当派"   : ({ "/d/wudang/wdroad1","/d/wudang/nanyuan1",
                       "/d/wudang/jindian","/d/wudang/shanlu4", }),
        "全真教"   : ({ "/d/quanzhen/shanlu4","/d/quanzhen/shijie7",
                       "/d/quanzhen/houshan","/d/quanzhen/datang3", }),
        "华山派"   : ({ "/d/huashan/buwei1","/d/huashan/qunxianguan",
                       "/d/huashan/songling1", }),
        "雪山寺"   : ({ "/d/xueshan/hubian1","/d/xueshan/chang",}),
        
        "峨嵋派"   : ({ "/d/emei/jinding","/d/emei/woyunan",
                       "/d/emei/hcazhengdian","/d/emei/xiaolu1", }),
        "桃花岛"   : ({ "/d/taohua/road1","/d/taohua/daojufang", }),
        "神龙教"   : ({ "/d/shenlong/damen","/d/shenlong/wuchang", }),
        "古墓派"   : ({ "/d/gumu/zhenting","/d/gumu/qianting", }),
        "星宿派"   : ({ "/d/xingxiu/xxh1","/d/xingxiu/xxh2", }),


]);

mapping place = ([
        "扬州城"   : ({ "/d/city/beimen", "/d/city/nanmen",
                        "/d/city/ximen", "/d/city/dongmen", }),
         "长安城"   : ({ "/d/changan/dong-chengmen", "/d/changan/nan-chengmen",
                        "/d/changan/xi-chengmen", "/d/changan/bei-chengmen",
                        "/d/changan/qinglong2", "/d/changan/baihu2", }),
        
        "汝州一带" : ({ "/d/shaolin/ruzhou" }),
        "成都城"   : ({ "/d/city3/southroad1", "/d/city3/qingyanggong",
                        "/d/city3/northroad2", }),

        "苏州城"   : ({ "/d/suzhou/xidajie2", "/d/suzhou/dongdajie2",
                        "/d/suzhou/road5", "/d/suzhou/road1",
                        "/d/suzhou/gumujiaohe", "/d/suzhou/zhenquting", }),
        "杭州城"   : ({ "/d/hangzhou/suti2", "/d/hangzhou/jujingyuan",
                        "/d/hangzhou/liuzhuang", "/d/hangzhou/road19",
                        "/d/hangzhou/huangniling", "/d/hangzhou/qinglindong", }),
        "襄阳城"   : ({ "/d/xiangyang/westjie2", "/d/xiangyang/southjie2",
                        "/d/xiangyang/xiaorong1", "/d/xiangyang/zhonglie",
                        "/d/xiangyang/guangchang", "/d/xiangyang/dingzi", }),
        "泉州城"   : ({ "/d/quanzhou/zhongxin", }),
        "福州城"   : ({ "/d/fuzhou/ximendajie", "/d/fuzhou/dongxiaojie",
                        "/d/fuzhou/nanmen", }),
         "关外"     : ({ "/d/guanwai/baihe", "/d/guanwai/road8",
                        "/d/guanwai/xuedi1", "/d/guanwai/beicheng",
                        "/d/guanwai/shanshenmiao" }),
        "大理一带" : ({ "/d/dali/northgate", "/d/dali/southgate",
                        "/d/dali/shanlu2", "/d/dali/buxiongbu",
                        "/d/dali/jinzhihe", "/d/dali/xiaodao1",
                        "/d/dali/tianweijing", "/d/dali/wuding",
                        "/d/dali/luwang", "/d/dali/gudao",
                        "/d/dali/biluoxueshan", "/d/dali/zhenxiong",

                        "/d/dali/yixibu", "/d/dali/cangshanzhong",
                        "/d/dali/wumeng", "/d/dali/hongsheng", }),
]);
int not_wizard(object ob);

void create()
{
        set("short", "太平洋");
        set("long", HIY @LONG
                          ,|
                            //|
                         // '/
                      //''/'|
                   /'/ / / /
                  ( ( /'//'
                   \~\\///|                     ___~~~~~-------/
           ,,))))))):::\/~-                _ ~      -----''/ '
   _______))))))))))))))::>/\         _~~~        ~~..----/
     ````\(((((''''((((((((>~ \     /  --    ~~~~~~~~'''/
        (\((''       ")))))), \ \ /      ,,,,,, ''''''/
       ))|  @    :-.   (((((((( /      _______  /```'
      (  '|    /   )      ))) /     ~~~   -- ' /
          |   |    |       (/              ~~~  ~ ___
          o_) ;   :        (        _____~~~      --   `
                 :       (  ' ____~~~~~                 . _
                |                ....                 '''__ `
          ..____/\/~     ,,                  ~/         |   \ \
      /  //"  . _____"'\_________------_____(        /        |  "
     / /  | /                            |  /\    /            |  \\
    (<:_  | :                           /  /   \  \             \ \\\
     \_|  ||:_.                       /  /'-----"  )              \\\\
          '\_ |                      ( /__:~~~~~~~~
                                      \ :__
                                        \__\
LONG NOR
        );
        
        
        set("sleep_room",1);
        set("objects",([
        ]));


set("exits", ([ /* sizeof() == 1 */

//    "west" : __DIR__"dmyuan2",
]));
        setup();
}

void init()
{
        add_action("do_zuan", "zuan");
        add_action("do_fei", "fei");
        add_action("do_sleep","shuijiao");
        add_action("start_quest","groupquest");
}


int do_zuan(string arg)
{
   object me;
   me = this_player();
   if ( !arg )
   {
      message_vision("你想干什么？\n",me);
      return 1;
   }

   if (arg == "dong") 
   {
        message_vision("$N没有别的办法可想，只好猫着腰钻进石道里面。\n",me);
        me->start_busy(1);
        message_vision("$N不知钻了多久，只觉眼前一亮，来到了外面。\n",me);
        me->start_busy(1);
        me->move("/d/city/guangchang");
        return 1;
   }

}

int do_fei(string arg)
{
        object me;
        me = this_player();
             if ((string)me->query("id") != "rama")
        return notify_fail("你有翅膀吗？\n");
        
        message_vision("$N拍拍翅膀飞走了。\n",me);
        me->move("d/city/kedian");
        return 1;
}

int do_sleep(string arg)
{
        object me;
        me= this_player();
//      if ((time()-me->query("last_sleep"))<0)
//        return notify_fail("你刚睡过一觉，先活动活动吧。 \n");
        message_vision("$N往乌鸦巢中一躺，迷迷糊糊就睡着了。\n",me);
        me->set_temp("sleeped",1);
        me->set_temp("block_msg/all",1);
        me->set("last_sleep",time());
        me->set("no_get", 1);
        me->set("no_get_from", 1);
        me->disable_player("<睡梦中>");
        call_out("wakeup",0,me);
        return 1;
}
void wakeup(object me)
{
        if(!me) return;
        me->set("qi",    2*me->query("eff_qi"));
        me->set("jing",  2*me->query("eff_jing"));
        me->set("jingli", 2*me->query("eff_jingli"));
        me->set("neili", 2*me->query("max_neili"));
        me->enable_player();
        call_out("del_sleeped", 0, me);
        message_vision("$N被一阵乌鸦的叫声吵醒了。\n",me);
        me->set_temp("block_msg/all", 0);
        write("你被乌鸦的叫声吵醒了。\n");
        me->delete("no_get");
        me->delete("no_get_from");

}

void del_sleeped(object me)
{
        if (objectp(me) &&  me->query_temp("sleeped"))
                me->delete_temp("sleeped");
}

void start_quest()
{
        string *kp;
        string p,arg,title,pp;
        string startroom;
        object pos,*all_user,ob;
        string the_nation,the_enemy;
        mapping fam_map,party_map;
        int i,all,lvl,num;

        fam_map = ([]);
        party_map = ([]);

        num = 5;
        switch (num)
        {

                case 0:
                case 1:
                case 2:
                        arg = "外敌入侵";
                        kp = keys(place);
                        p = kp[random(sizeof(kp))];
                        all_user = users();
                        all_user = filter_array(all_user,(: $1->query("combat_exp") > 200000 :));
                        all_user = filter_array(all_user,(: not_wizard :));
                        this_player()->set("test",all_user);
                        all = sizeof(users())/2;
                        if (all<10) return;                     //玩家太少，终止本次进程。
                        if (all>60) all = 60;
                        break;
                case 3:
                        arg = "门派";
                        kp = keys(family);
                        for (i = 0;i < sizeof (kp);i ++)
                        {
                                p = kp[i];
                                all_user = users();
                                all_user = filter_array(all_user,(: $1->query("family/family_name") == $2 :),p);
                                all_user = filter_array(all_user,(: not_wizard :));
                                if (!sizeof(all_user)) continue;        //该门派没有玩家在线
                                fam_map += ([ p:sizeof(all_user) ]);
                        }
                        if (!sizeof(fam_map)) return;           //MUD中没有属于任何一个门派的玩家                                
                        this_player()->set("test",fam_map);
                        kp = keys(fam_map);
                        p = kp[random(sizeof(kp))];
                        all = fam_map[p];
                        if (all < 5) all = 5;
                        if (all > 20) all = 30 - random(10);
                        break;
                default:
                        break;
        }
}

int not_wizard(object ob)
{
        if (wizardp(ob)) return 0;
        return 1;
}

