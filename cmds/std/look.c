// Code of ShenZhou
// look.c
// modified by sdong for biaoche, 12/23/98

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env)
{
        int i;
        object *inv;
        mapping exits;
        string str, *dirs;

        if( !env ) {
                write("你的四周灰蒙蒙地一片，什么也没有。\n");
                return 1;
        }
        str = sprintf( "%s - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env): "[mud.ren]",
                (file_name(env) == "/d/wizard/meeting_room" )?env->update_here():env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                        str += "    这里没有任何明显的出路。\n";
                else if( sizeof(dirs)==1 )
                        str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                else
                        str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                if( objectp(inv[i]->query("rider")) ) continue;
                else inv[i]->delete("rider");


                if( objectp(inv[i]->query("rided")) ) {
                        str += "  " + inv[i]->short() + "骑在" +
                        (inv[i]->query("rided"))->name() + "上";
                if( stringp(inv[i]->query_temp("exit_blocked")))
                                                                str += "挡着往"+inv[i]->query_temp("exit_blocked")+
                                                                "去的路";
                        str += "\n";
                }
                else {
                        if (stringp(inv[i]->query_temp("exit_blocked")))
                        str += "  " + inv[i]->short() + "挡着往" + inv[i]->query_temp("exit_blocked")
                                +"去的路\n";
                        else if( inv[i]->query_temp("riding") ) {
                                str += "  " + inv[i]->short() + "坐在镖车上\n";
                        }
						else if( inv[i]->query_temp("on_bantan") )
						{
                                str += "  " + inv[i]->short() + HIW+" < 摆 摊 中 >\n"+NOR;
                        }
                        else if( inv[i]->query_temp("pending/heal_other") == me )
                                str += replace_string("  " + inv[i]->short() + "\n", me->name(), "你");
                        else
                                str += "  " + inv[i]->short() + "\n";
                        inv[i]->delete("rided");
                }
        }


        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;

        write(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("里面有：\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

int look_living(object me, object obj)
{
        string str, limb_status, pro;
		int per;
        mixed *inv;
        mapping my_fam, fam;

        if(( me!=obj )&& (environment(me) == environment(obj))) {
          if ( !wizardp(me) || (wizardp(me) && !wizardp(obj) && !me->query("env/invisibility")) )
                message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);
        }

        str = obj->long();
  per = obj->query_per();

        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if( objectp(obj->query("rided")) )
                str += sprintf(pro +  "骑在" + (obj->query("rided"))->name() + "上。\n");

        if( (string)obj->query("race")=="人类"
        &&      intp(obj->query("age")) )
                str += sprintf("%s看起来约%s多岁。\n", pro,
                        chinese_number(
                        (obj->query("age")-SKILL_D("beauty")->reduce_age(obj)) / 10 * 10));

        if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
        {
				if(wizardp(obj))
						str+=sprintf(HIY"%s全身散发着耀眼的金光，看来是万物之尊的神类。\n"NOR,pro);
                if (per >=40)
                        str +=pro+ HIG"现在一派神人气度，仙风道骨，举止出尘。\n";
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"现在神清气爽，骨格清奇，宛若仙人。\n";
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"现在飘逸出尘，潇洒绝伦。\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"生得英俊潇洒，风流倜傥。\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"生得目似点漆，高大挺俊，令人心动。\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"生得面若秋月，儒雅斯文，举止适度。\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"生得眉如双剑，眼如明星，英挺出众。\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"生得相貌平平，不会给人留下什么印象。\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"生得獐头鼠须，让人一看就不生好感。\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"生得呲牙咧嘴，黑如锅底，奇丑无比。\n"NOR;
                if (per <= 10)
                        str +=pro+ RED"生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "女性")
            {
                if (per >=40)
                        str +=pro+ HIW"现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物\n"NOR;
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"现在美若天仙，不沾一丝烟尘。\n"NOR;
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n";
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"生得巧笑嫣然，宛约可人。\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"生得如梨花带露，清新秀丽。\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"生得风姿楚楚，明丽动人。\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"生得虽不标致，倒也白净，有些动人之处。\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"生得一嘴大暴牙，让人一看就没好感。\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
				if (per <=10)
                        str +=pro+ RED"生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;
            }
            else
            {
                if (living(obj))
		{
                if (!obj->query_temp("owner"))
                   str += pro+"是一只未被驯服的畜生，眼光里满是戒心和敌意。\n";
                else
                   str += pro+"是一只被"+obj->query_temp("ownername")+"驯服的畜生，一副很温驯的样子。\n";
		}
            }
        }

        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      environment(me) == environment(obj)
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "男性" ||
                                (string)obj->query("gender") == "无性")
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }

////////////////////////////////////////////////////////////////////////////////////////////////////
        if (me->is_jiebai_of(obj))
        {
              if( obj->query("gender")=="女性" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的义姐。\n", pro);
                    else
                        str += sprintf("%s是你的结义妹子。\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的结义兄长。\n", pro);
                    else
                        str += sprintf("%s是你的义弟。\n", pro);
              }
        }
////////////////////////////////////////////////////////////////////////////add jiebai list by lisser
        if( obj->is_spouse_of(me) )
                str += pro + "是你的" + me->query("spouse/title") + "。\n";

        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me && !obj->is_spouse_of(me)
        &&      living(obj)
        &&      random(-(int)obj->query("shen")) > (int)me->query("int") * 10 ) {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
              if ((int)me->query("combat_exp") > 100000) COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("embedded") )
                str = HIR "  √" NOR + str;
        else if( obj->query("equipped") )
                str = HIC "  □" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}

int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。

HELP
);
        return 1;
}
