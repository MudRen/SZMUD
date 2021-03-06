// Code of ShenZhou
// rankd.c
// 1996-02-15 dts ranking related to "shen"
// 1996-11-26 xbc added emei ranking
// 2001-7-12  add by rider
// 2001-7-27  huaishi 更改巫师 rank 
#include <ansi.h>

string query_rank(object ob)
{
        int shen;
        int budd;
        int rank;
        int lama;
        int maha;
        int pixie;
        int dlrank;
        int taoism;
        int tjsg,btxg,hama,qqsh,hgdf,ynxj,htqg,zxg;

        
        if( ob->is_ghost() && ob->query("gender") == "女性")
                return HIB "【 幽    灵 】" NOR;
        if( ob->is_ghost() && ob->query("gender") == "男性")
                return HIB "【 鬼    魂 】" NOR;

        shen = ob->query("shen");

        if ( ob->query("family/family_name") == "少林派" )
                budd = ob->query_skill("hunyuan-yiqi",1);

        if ( ob->query("family/family_name") == "武当派" )
                tjsg = ob->query_skill("taiji-shengong",1);

        if ( ob->query("family/family_name") == "丐帮" )
                htqg = ob->query_skill("huntian-qigong",1);

        if ( ob->query("family/family_name") == "雪山派" ||
                  ob->query("family/family_name") == "血刀门" )
                lama = ob->query_skill("longxiang-banruo",1);

        if ( ob->query("family/family_name") == "峨嵋派" )
                maha = ob->query_skill("linji-zhuang",1);

        if ( ob->query("family/family_name") == "全真教" )
                taoism = ob->query_skill("xiantian-gong",1);
        
        if ( ob->query("family/family_name") == "桃花岛" )
                btxg = ob->query_skill("bitao-xuangong",1);
        
        if ( ob->query("family/family_name") == "星宿派" )
                hgdf = ob->query_skill("huagong-dafa",1);
        
        if ( ob->query("family/family_name") == "白驼山" )
                hama = ob->query_skill("hamagong",1);
        
        if ( ob->query("family/family_name") == "昆仑派" )
                qqsh = ob->query_skill("qinqi-shuhua",1);

        if ( ob->query("family/family_name") == "华山派" )
                zxg = ob->query_skill("zixia-gong",1);  
        
        if ( ob->query("family/family_name") == "古墓派" )
                ynxj = ob->query_skill("yunu-xinjing",1);       


        if (ob->query("dali/employee"))
                dlrank = ob->query("dali/rank");

        // the following was to set class for those who became gonggong
        // before mongol add class eunuch
        //if ( ob->query("gender") == "无性" )
        //      ob->set("class", "eunuch");
        // should be eunach.  The following lines can be removed
        // after Aug 1/97 , except that line of "pixie =...
        //      if ( ob->query("class")=="eunuch") ob->set("class","eunach");
        if (ob->query("class")=="eunach") {
                ob->delete("rank_info/respect");
                ob->delete("rank_info/rude");
        }
        pixie = ob->query_skill("pixie-jian", 1);
                  if (pixie<60 && ob->query("class")=="eunach") ob->delete("class");
        // remove the above line after 8/1/97, except the line of "pixie =..

        switch(ob->query("gender")) {
        case "女性":
                switch(wizhood(ob)) {
              case "(admin)": 
                        return HIW "【 天    帝 】" NOR; 
              case "(arch)": 
                     return HIY "【 天    神 】" NOR; 
              case "(wizard)": 
                     return HIG "【 逸    仙 】" NOR; 
              case "(virtuoso)": 
                     return HIC "【 管理神仙 】" NOR; 
              case "(designer)": 
                     return HIC "【 羽    仙 】" NOR; 
              case "(caretaker)": 
                     return HIG "【 管理神仙 】" NOR; 
              case "(creator)": 
                     return YEL "【 管理候选 】" NOR; 
              case "(apprentice)": 
                     return CYN "【 神仙学徒 】" NOR; 
              case "(immortal)": 
                     return HIM "【 精    灵 】" NOR; 
                default:
                        switch(ob->query("family/family_name")) {
                        case "峨嵋派":
                                if (maha >= 500 )
                                        return HIW "【 神　  尼 】" NOR;
                                else if (maha >= 450)
                                        return  HIR"【 仙    姑 】" NOR;
                                else if (maha >= 400)
                                        return  HIR"【 师    太 】" NOR;
                                else if (maha >= 300)
                                        return HIM"【 比 丘 尼 】" NOR;
                                else if (maha >= 200)
                                        return HIM"【 沙 弥 尼 】" NOR;
                                else if (maha >= 100)
                                        return "【 学 戒 女 】" NOR;
                                else   return "【 小 尼 姑 】" NOR;
 

                case "全真教":
                        if (taoism >= 450)
                                return HIW "【 女 真 人 】" NOR;
                        else if (taoism >= 300)
                                return HIR"【 大 女 冠 】" NOR;
                        else if (taoism >= 150)
                                return  HIM"【 女    冠 】" NOR;
                        else
                                return     "【 小 道 姑 】" NOR;

                        case "大理段家":
                                if (dlrank==5)
                                        return HIW "【 王    妃 】" NOR;
                                else if (dlrank==4)
                                        return HIR"【 诰命夫人 】" NOR;
                                else
                                        return "【 女    官 】" NOR;
                
                        case "丐帮":            
                                if (htqg >= 500)
                                        return HIW "【 女 神 丐 】" NOR;
                                else if (htqg >= 450)
                                        return HIR"【 执法长老 】" NOR;
                                else if (htqg >= 400)
                                        return HIR"【 传功长老 】" NOR;
                                else if (htqg >= 300)
                                        return HIM"【 掌钹龙头 】" NOR;
                                else if (htqg >= 200)
                                        return HIM"【 掌棒龙头 】" NOR;
                                else if (htqg >= 100)
                                        return "【 叫 化 婆 】" NOR;
                                else
                                        return "【 叫 化 妹 】" NOR;
                        case "武当派":
                                if (tjsg >= 500)
                                        return HIW "【 女 剑 仙 】" NOR;
                                else if (tjsg >= 300)
                                        return HIR"【 女 剑 侠 】" NOR;
                                else if (tjsg >= 150)
                                        return HIM"【 女 剑 客 】" NOR;
                                else
                                        return "【 小 剑 童 】" NOR;
                        case "桃花岛":
                                if (btxg >= 450)
                                        return HIW "【 小 东 邪 】" NOR;
                                else if (btxg >= 400)
                                        return HIR"【 占 卜 师 】" NOR;
                                else if (btxg >= 300)
                                        return HIR"【 术    士 】" NOR;
                                else if (btxg >= 200)
                                        return HIM"【 神 算 子 】" NOR;
                                else if (btxg >= 100)
                                        return "【 桃花仆人 】" NOR;

                                else
                                        return "【 小 丫 鬟 】" NOR;
                        case "星宿派":
                                if (hgdf >= 500)
                                        return HIW "【 星宿神女 】" NOR;
                                else if (hgdf >= 400)
                                        return HIR"【 星宿护法 】" NOR;
                                else if (hgdf >= 300)
                                        return HIM"【 星宿使者 】" NOR;
                                else if (hgdf >= 200)
                                        return HIM"【 星宿大仙 】" NOR;
                                else if (hgdf >= 100)
                                        return "【 星宿小仙 】" NOR;
                                else
                                        return "【星宿女弟子】" NOR;

                        case "白驼山":
                                if (hama >= 500)
                                        return HIW "【 百毒仙子 】" NOR;
                                else if (hama >= 450)
                                        return HIR"【白驼山主人】" NOR;
                                else if (hama >= 400)
                                        return HIR"【白驼山少主】" NOR;
                                else if (hama >= 300)
                                        return HIM"【白驼山管家】" NOR;
                                else if (hama >= 200)
                                        return HIM"【白驼山侍女】" NOR;
                                else
                                        return "【白驼山婢女】" NOR;
                        case "昆仑派":
                                if (qqsh >= 400)
                                        return HIW "【 状    元 】" NOR;
                                else if (qqsh >= 350)
                                        return HIR"【 榜    眼 】" NOR;
                                else if (qqsh >= 300)
                                        return HIM"【 探    花 】" NOR;
                                else if (qqsh >= 200)
                                        return HIM"【 进    士 】" NOR;
                                else if (qqsh >= 100)
                                        return "【 秀    才 】" NOR;
                                else
                                        return "【 学    士 】" NOR;

        
                        case "华山派":
                                if ( zxg >= 500 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIW "【 剑    痴 】" NOR;
                                else if (zxg >= 500)
                                        return HIW"【 剑    圣 】" NOR;
                                else if (zxg >= 360 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIR"【 剑宗高手 】" NOR;
                                else if (zxg >= 360)
                                        return HIR"【 气宗高手 】" NOR;
                                else if (zxg >= 200 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIM"【 剑宗弟子 】" NOR;
                                else if (zxg >= 200)
                                        return HIM"【 气宗弟子 】" NOR;
                                else
                                        return "【华山小剑客】" NOR;

                        case "古墓派":
                                if (ynxj >= 500)
                                        return HIW "【 情    圣 】" NOR;
                                else if (ynxj >= 400)
                                        return HIR"【 情    痴 】" NOR;
                                else if (ynxj >= 300)
                                        return HIR"【痴情女剑客】" NOR;
                                else if (ynxj >= 200)
                                        return HIM"【 游龙侠女 】" NOR;
                                else if (ynxj >= 100)
                                        return "【 古墓侍剑 】" NOR;
                                else
                                        return "【 古墓侍女 】" NOR;

                        default:
                                if (ob->query("combat_exp") > 1000000)
                                        return  "【 武林名宿 】" NOR;
                                else   return  "【 民    女 】" NOR;

                        }
                }
        default:
                switch(wizhood(ob)) {
                     case "(admin)": 
                             return HIW "【 天    帝 】" NOR; 
                     case "(arch)": 
                             return HIY "【 天    神 】" NOR; 
                     case "(wizard)": 
                             return HIG "【 逸    仙 】" NOR; 
                     case "(virtuoso)": 
                             return HIC "【 管理神仙 】" NOR; 
                     case "(designer)": 
                             return HIC "【 羽    仙 】" NOR; 
                     case "(caretaker)": 
                             return HIG "【 管理神仙 】" NOR; 
                     case "(creator)": 
                             return YEL "【 管理候选 】" NOR; 
                     case "(apprentice)": 
                             return CYN "【 神仙学徒 】" NOR; 
                     case "(immortal)": 
                             return CYN "【 精    灵 】" NOR;   
                default:
                switch(ob->query("family/family_name")) {
                        case "峨嵋派":
                                if (maha >= 400 )
                                        return HIW "【 旷世大侠 】" NOR;
                                else if (maha >= 300)
                                        return WHT"【 大    侠 】" NOR;
                                else if (maha >= 200)
                                        return WHT"【 侠    客 】" NOR;
                                else if (maha >= 100)
                                        return "【 少    侠 】" NOR;
                        
                                else   return "【 小    侠 】" NOR;
 

                case "全真教":
                        if (taoism >= 500)
                                return HIW "【 中 神 通 】" NOR;
                        else if (taoism >= 450)
                                return HIC"【 真    人 】" NOR;
                        else if (taoism >= 400)
                                return HIC"【 天    师 】" NOR;
                        else if (taoism >= 300)
                                return HIG"【 黄    冠 】" NOR;
                        else if (taoism >= 200)
                                return HIG"【 道学宗师 】" NOR;
                        else if (taoism >= 100)
                                return "【 道学大师 】" NOR;
                        else
                                return     "【 小 道 士 】" NOR;

                        case "大理段家":
                                if (dlrank==5)
                                        return HIW"【 王    爷 】" NOR;
                                else if (dlrank==4)
                                        return HIC"【 侯    爷 】";
                                else if (dlrank==3)
                                        return "【 武    将 】";
                                else if (dlrank<=2)
                                        return "【 官    差 】";
                        case "丐帮":            
                                if (htqg >= 550)
                                        return HIW "【 北    丐 】" NOR;
                                else if (htqg >= 450)
                                        return HIC"【 执法长老 】" NOR;
                                else if (htqg >= 400)
                                        return HIC"【 传功长老 】" NOR;
                                else if (htqg >= 300)
                                        return HIG"【 掌钹龙头 】" NOR;
                                else if (htqg >= 200)
                                        return HIG"【 掌棒龙头 】" NOR;
                                else if (htqg >= 100)
                                        return "【 丐帮弟子 】" NOR;
                                else
                                        return "【 小 叫 化 】" NOR;
                        case "武当派":
                                if (tjsg >= 500)
                                        return HIW "【 天下一剑 】" NOR;
                                else if (tjsg >= 400)
                                        return HIC"【 剑    仙 】" NOR;
                                else if (tjsg >= 300)
                                        return HIG"【 武当七侠 】" NOR;
                                else if (tjsg >= 150)
                                        return HIG"【 武当剑客 】" NOR;
                                else
                                        return "【 小 剑 童 】" NOR;
                        case "桃花岛":
                                if (btxg >= 500)
                                        return HIW "【 东    邪 】" NOR;
                                else if (btxg >= 450)
                                        return HIC"【 小 东 邪 】" NOR;
                                else if (btxg >= 400)
                                        return HIC"【 占 卜 师 】" NOR;
                                else if (btxg >= 300)
                                        return HIG"【 术    士 】" NOR;
                                else if (btxg >= 150)
                                        return HIG"【 神 算 子 】" NOR;
                                else if (btxg >= 100)
                                        return "【 桃花仆人 】" NOR;

                                else
                                        return "【 桃花仆人 】" NOR;
                        case "星宿派":
                                if (hgdf >= 500)
                                        return HIW "【 星宿老仙 】" NOR;
                                else if (hgdf >= 400)
                                        return HIC"【 星宿护法 】" NOR;
                                else if (hgdf >= 300)
                                        return HIG"【 星宿使者 】" NOR;
                                else if (hgdf >= 200)
                                        return HIG"【 星宿大仙 】" NOR;
                                else if (hgdf >= 100)
                                        return "【 星宿小仙 】" NOR;
                                else
                                        return "【 星宿弟子 】" NOR;

                        case "白驼山":
                                if (hama >= 600)
                                        return HIW "【 西    毒 】" NOR;
                                else if (hama >= 500)
                                        return HIC"【白驼山主人】" NOR;
                                else if (hama >= 400)
                                        return HIC"【白驼山少主】" NOR;
                                else if (hama >= 300)
                                        return HIG"【白驼山管家】" NOR;
                                else if (hama >= 200)
                                        return HIG"【白驼山打手】" NOR;
                                else
                                        return "【白驼山武师】" NOR;
                        case "昆仑派":
                                if (qqsh >= 400)
                                        return HIW "【 状    元 】" NOR;
                                else if (qqsh >= 350)
                                        return HIC"【 榜    眼 】" NOR;
                                else if (qqsh >= 300)
                                        return HIG"【 探    花 】" NOR;
                                else if (qqsh >= 200)
                                        return "【 进    士 】" NOR;
                                else if (qqsh >= 100)
                                        return "【 秀    才 】" NOR;
                                else
                                        return "【 学    士 】" NOR;

        
                        case "华山派":
                                if ( zxg >= 500 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIW "【 剑    痴 】" NOR;
                                else if (zxg >= 500)
                                        return HIW "【 剑    圣 】" NOR;
                                else if (zxg >= 360 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIC"【 剑宗高手 】" NOR;
                                else if (zxg >= 360)
                                        return HIC"【 气宗高手 】" NOR;
                                else if (zxg >= 200 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIG"【 剑宗弟子 】" NOR;
                                else if (zxg >= 200)
                                        return HIG"【 气宗弟子 】" NOR;
                                else
                                        return "【华山小剑客】" NOR;

                        case "古墓派":
                                if (ynxj >= 500)
                                        return HIW "【 情    圣 】" NOR;
                                else if (ynxj >= 450)
                                        return HIC"【 情    痴 】" NOR;
                                else if (ynxj >= 350)
                                        return HIC"【 痴情剑客 】" NOR;
                                else if (ynxj >= 200)
                                        return HIG"【 游 龙 侠 】" NOR;
                                else if (ynxj >= 100)
                                        return "【 古墓剑客 】" NOR;
                                else
                                        return "【古墓小剑客】" NOR;
                                
                        case "少林派":
                                if (budd >= 500)
                                        return HIW "【心禅堂长老】" NOR;
                                else if (budd >= 450)
                                        return HIY"【达摩院首座】" NOR;
                                else if (budd >= 400)
                                        return HIY"【罗汉堂首座】" NOR;
                                else if (budd >= 350)
                                        return HIY"【 长    老 】" NOR;
                                else if (budd >= 300)
                                        return HIY"【 圣    僧 】" NOR;
                                else if (budd >= 250)
                                        return HIY"【 罗    汉 】" NOR;
                                else if (budd >= 200)
                                        return "【 尊    者 】" NOR;
                                else if (budd >= 150)
                                        return "【 禅    师 】" NOR;
                                else if (budd >= 100)
                                        return "【 比    丘 】" NOR;
                                else
                                        return "【 僧    人 】" NOR;
                                
                
                        case "雪山派":
                                if ( lama>= 550)
                                        return HIW "【 明    王 】" NOR;
                               else if (lama >= 500)
                                        return HIY"【 转 轮 王 】" NOR;
                                else if (lama >= 400)
                                        return HIY"【 法    王 】" NOR;
                               else if (lama >= 300)
                                        return HIY"【 活    佛 】" NOR;
                                else if (lama >= 200)
                                        return HIY"【 国    师 】" NOR;
                                else if (lama >= 100)
                                        return "【 大 喇 嘛 】" NOR;
                                else
                                        return "【 灵    童 】" NOR;

                        default:
                                if (ob->query("combat_exp") > 1000000)
                                        return  "【 武林名宿 】" NOR;
                                else   return  "【 平    民 】" NOR;

                        }

                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师太";
                                else return "师太";
                                break;

                        case "taoist":
                                if( age < 18 ) return "小仙姑";
                                else return "仙姑";

                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "娘娘";
                                else if (ob->query("dali/rank")==4)
                                        return "贵夫人";
                                else {
                                        if( age < 18 ) return "小姑娘";
                                        else if( age < 50 ) return "姑娘";
                                        else return "婆婆";
                                }
                                break;
                        default:
                                if( age < 18 ) return "小姑娘";
                                else if( age < 50 ) return "姑娘";
                                else return "婆婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师父";
                                else return "大师";
                                break;
                        case "lama":
                                if( age < 25 ) return "小师父";
                                else return "上人";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小道兄";
                                else return "道长";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "小老弟";
                                else if( age < 50 ) return "壮士";
                                else return "老前辈";
                                break;
                        case "eunach":
                                if (ob->query_skill("pixie-jian",1)>160)
                                        return "督公";
                                if (age <18) return "小公公";
                                else if (age < 50) return "公公";
                                else return "老公公";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "王爷";
                                else if (ob->query("dali/rank")==4)
                                        return "侯爷";
                                else if (ob->query("dali/rank")==3)
                                        return "将军";
                                else return "差爷";
                                break;
                        default:
                                if( age < 20 ) return "小兄弟";
                                else if( age < 50 ) return "壮士";
                                else return "老爷子";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "贼尼";
                                break;
                        case "taoist":
                                return "妖女";
                                break;
                        default:
                                if( age < 18 ) return "小贱人";
                                else if( age < 50 ) return "贱人";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "lama":
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                return "死牛鼻子";
                                break;
                        case "eunach":
                                return "阉贼";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "狗王";
                                else if (ob->query("dali/rank")>=3)
                                        return "狗官";
                                else return "狗腿子";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 50 ) return "臭贼";
                                else return "老匹夫";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "小女子";
                                else if( age < 50 ) return "妾身";
                                else return "老身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫僧";
                                else return "老衲";
                                break;
                        case "lama":
                                if( age < 50 ) return "贫僧";
                                else return "老衲";
                                break;
                        case "eunach":
                                return "下官";
                                break;
                        case "taoist":
                                return "贫道";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "小王我";
                                else return "下官";
                                break;
                        default:
                                if( age < 50 ) return "在下";
                                else return "老头子";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age")-SKILL_D("beauty")->reduce_age(ob);
        switch(ob->query("gender")) {
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "本姑娘";
                                else return "老娘";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "大和尚我";
                                else return "老和尚我";
                                break;
                        case "eunach":
                                if (age < 50) return "本官";
                                else return "老身";
                                break;
                        case "lama":
                                if( age < 50 ) return "本佛爷";
                                else return "老佛爷我";
                                break;  
                        case "taoist":
                                return "本山人";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "本王";
                                else if (ob->query("dali/rank")==4)
                                        return "本侯";
                                else if (ob->query("dali/rank")==3)
                                        return "本官";
                                else return "差爷我";
                                break;
                        default:
                                if( age < 50 ) return "大爷我";
                                else return "老子";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(this_player()))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else 
                {       
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else 
        {       
                a1 = previous_object()->query("age");
                a2 = ob->query("age");
        }
                                                        
        switch (ob->query("gender")) {
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        case "无性" :
                if (ob->query("class")== "eunach") {
                if (a1 >= a2)
                        if (random(5)==1) return "妹妹";
                        else return "弟弟";
                else
                        if (random(5)==1) return "姐姐";
                        else return "哥哥";
                }
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
                break;
        }
}

string query_self_close(object ob)
{
        int a1, a2;
        string gender;
        
        if( objectp(this_player()) )
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else 
                {       
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
                gender = this_player()->query("gender");
        } else 
        {       
                a1 = previous_object()->query("age");
                a2 = ob->query("age");
                gender = previous_object()->query("gender");
        }
                
        switch (gender) {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
}
