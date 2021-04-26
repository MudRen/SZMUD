// Code of ShenZhou
// rankd.c
// 1996-02-15 dts ranking related to "shen"
// 1996-11-26 xbc added emei ranking
// 2001-7-12  add by rider
// 2001-7-27  huaishi ������ʦ rank 
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

        
        if( ob->is_ghost() && ob->query("gender") == "Ů��")
                return HIB "�� ��    �� ��" NOR;
        if( ob->is_ghost() && ob->query("gender") == "����")
                return HIB "�� ��    �� ��" NOR;

        shen = ob->query("shen");

        if ( ob->query("family/family_name") == "������" )
                budd = ob->query_skill("hunyuan-yiqi",1);

        if ( ob->query("family/family_name") == "�䵱��" )
                tjsg = ob->query_skill("taiji-shengong",1);

        if ( ob->query("family/family_name") == "ؤ��" )
                htqg = ob->query_skill("huntian-qigong",1);

        if ( ob->query("family/family_name") == "ѩɽ��" ||
                  ob->query("family/family_name") == "Ѫ����" )
                lama = ob->query_skill("longxiang-banruo",1);

        if ( ob->query("family/family_name") == "������" )
                maha = ob->query_skill("linji-zhuang",1);

        if ( ob->query("family/family_name") == "ȫ���" )
                taoism = ob->query_skill("xiantian-gong",1);
        
        if ( ob->query("family/family_name") == "�һ���" )
                btxg = ob->query_skill("bitao-xuangong",1);
        
        if ( ob->query("family/family_name") == "������" )
                hgdf = ob->query_skill("huagong-dafa",1);
        
        if ( ob->query("family/family_name") == "����ɽ" )
                hama = ob->query_skill("hamagong",1);
        
        if ( ob->query("family/family_name") == "������" )
                qqsh = ob->query_skill("qinqi-shuhua",1);

        if ( ob->query("family/family_name") == "��ɽ��" )
                zxg = ob->query_skill("zixia-gong",1);  
        
        if ( ob->query("family/family_name") == "��Ĺ��" )
                ynxj = ob->query_skill("yunu-xinjing",1);       


        if (ob->query("dali/employee"))
                dlrank = ob->query("dali/rank");

        // the following was to set class for those who became gonggong
        // before mongol add class eunuch
        //if ( ob->query("gender") == "����" )
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
        case "Ů��":
                switch(wizhood(ob)) {
              case "(admin)": 
                        return HIW "�� ��    �� ��" NOR; 
              case "(arch)": 
                     return HIY "�� ��    �� ��" NOR; 
              case "(wizard)": 
                     return HIG "�� ��    �� ��" NOR; 
              case "(virtuoso)": 
                     return HIC "�� �������� ��" NOR; 
              case "(designer)": 
                     return HIC "�� ��    �� ��" NOR; 
              case "(caretaker)": 
                     return HIG "�� �������� ��" NOR; 
              case "(creator)": 
                     return YEL "�� �����ѡ ��" NOR; 
              case "(apprentice)": 
                     return CYN "�� ����ѧͽ ��" NOR; 
              case "(immortal)": 
                     return HIM "�� ��    �� ��" NOR; 
                default:
                        switch(ob->query("family/family_name")) {
                        case "������":
                                if (maha >= 500 )
                                        return HIW "�� ��  �� ��" NOR;
                                else if (maha >= 450)
                                        return  HIR"�� ��    �� ��" NOR;
                                else if (maha >= 400)
                                        return  HIR"�� ʦ    ̫ ��" NOR;
                                else if (maha >= 300)
                                        return HIM"�� �� �� �� ��" NOR;
                                else if (maha >= 200)
                                        return HIM"�� ɳ �� �� ��" NOR;
                                else if (maha >= 100)
                                        return "�� ѧ �� Ů ��" NOR;
                                else   return "�� С �� �� ��" NOR;
 

                case "ȫ���":
                        if (taoism >= 450)
                                return HIW "�� Ů �� �� ��" NOR;
                        else if (taoism >= 300)
                                return HIR"�� �� Ů �� ��" NOR;
                        else if (taoism >= 150)
                                return  HIM"�� Ů    �� ��" NOR;
                        else
                                return     "�� С �� �� ��" NOR;

                        case "����μ�":
                                if (dlrank==5)
                                        return HIW "�� ��    �� ��" NOR;
                                else if (dlrank==4)
                                        return HIR"�� ھ������ ��" NOR;
                                else
                                        return "�� Ů    �� ��" NOR;
                
                        case "ؤ��":            
                                if (htqg >= 500)
                                        return HIW "�� Ů �� ؤ ��" NOR;
                                else if (htqg >= 450)
                                        return HIR"�� ִ������ ��" NOR;
                                else if (htqg >= 400)
                                        return HIR"�� �������� ��" NOR;
                                else if (htqg >= 300)
                                        return HIM"�� ������ͷ ��" NOR;
                                else if (htqg >= 200)
                                        return HIM"�� �ư���ͷ ��" NOR;
                                else if (htqg >= 100)
                                        return "�� �� �� �� ��" NOR;
                                else
                                        return "�� �� �� �� ��" NOR;
                        case "�䵱��":
                                if (tjsg >= 500)
                                        return HIW "�� Ů �� �� ��" NOR;
                                else if (tjsg >= 300)
                                        return HIR"�� Ů �� �� ��" NOR;
                                else if (tjsg >= 150)
                                        return HIM"�� Ů �� �� ��" NOR;
                                else
                                        return "�� С �� ͯ ��" NOR;
                        case "�һ���":
                                if (btxg >= 450)
                                        return HIW "�� С �� а ��" NOR;
                                else if (btxg >= 400)
                                        return HIR"�� ռ �� ʦ ��" NOR;
                                else if (btxg >= 300)
                                        return HIR"�� ��    ʿ ��" NOR;
                                else if (btxg >= 200)
                                        return HIM"�� �� �� �� ��" NOR;
                                else if (btxg >= 100)
                                        return "�� �һ����� ��" NOR;

                                else
                                        return "�� С Ѿ �� ��" NOR;
                        case "������":
                                if (hgdf >= 500)
                                        return HIW "�� ������Ů ��" NOR;
                                else if (hgdf >= 400)
                                        return HIR"�� ���޻��� ��" NOR;
                                else if (hgdf >= 300)
                                        return HIM"�� ����ʹ�� ��" NOR;
                                else if (hgdf >= 200)
                                        return HIM"�� ���޴��� ��" NOR;
                                else if (hgdf >= 100)
                                        return "�� ����С�� ��" NOR;
                                else
                                        return "������Ů���ӡ�" NOR;

                        case "����ɽ":
                                if (hama >= 500)
                                        return HIW "�� �ٶ����� ��" NOR;
                                else if (hama >= 450)
                                        return HIR"������ɽ���ˡ�" NOR;
                                else if (hama >= 400)
                                        return HIR"������ɽ������" NOR;
                                else if (hama >= 300)
                                        return HIM"������ɽ�ܼҡ�" NOR;
                                else if (hama >= 200)
                                        return HIM"������ɽ��Ů��" NOR;
                                else
                                        return "������ɽ�Ů��" NOR;
                        case "������":
                                if (qqsh >= 400)
                                        return HIW "�� ״    Ԫ ��" NOR;
                                else if (qqsh >= 350)
                                        return HIR"�� ��    �� ��" NOR;
                                else if (qqsh >= 300)
                                        return HIM"�� ̽    �� ��" NOR;
                                else if (qqsh >= 200)
                                        return HIM"�� ��    ʿ ��" NOR;
                                else if (qqsh >= 100)
                                        return "�� ��    �� ��" NOR;
                                else
                                        return "�� ѧ    ʿ ��" NOR;

        
                        case "��ɽ��":
                                if ( zxg >= 500 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIW "�� ��    �� ��" NOR;
                                else if (zxg >= 500)
                                        return HIW"�� ��    ʥ ��" NOR;
                                else if (zxg >= 360 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIR"�� ���ڸ��� ��" NOR;
                                else if (zxg >= 360)
                                        return HIR"�� ���ڸ��� ��" NOR;
                                else if (zxg >= 200 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIM"�� ���ڵ��� ��" NOR;
                                else if (zxg >= 200)
                                        return HIM"�� ���ڵ��� ��" NOR;
                                else
                                        return "����ɽС���͡�" NOR;

                        case "��Ĺ��":
                                if (ynxj >= 500)
                                        return HIW "�� ��    ʥ ��" NOR;
                                else if (ynxj >= 400)
                                        return HIR"�� ��    �� ��" NOR;
                                else if (ynxj >= 300)
                                        return HIR"������Ů���͡�" NOR;
                                else if (ynxj >= 200)
                                        return HIM"�� ������Ů ��" NOR;
                                else if (ynxj >= 100)
                                        return "�� ��Ĺ�̽� ��" NOR;
                                else
                                        return "�� ��Ĺ��Ů ��" NOR;

                        default:
                                if (ob->query("combat_exp") > 1000000)
                                        return  "�� �������� ��" NOR;
                                else   return  "�� ��    Ů ��" NOR;

                        }
                }
        default:
                switch(wizhood(ob)) {
                     case "(admin)": 
                             return HIW "�� ��    �� ��" NOR; 
                     case "(arch)": 
                             return HIY "�� ��    �� ��" NOR; 
                     case "(wizard)": 
                             return HIG "�� ��    �� ��" NOR; 
                     case "(virtuoso)": 
                             return HIC "�� �������� ��" NOR; 
                     case "(designer)": 
                             return HIC "�� ��    �� ��" NOR; 
                     case "(caretaker)": 
                             return HIG "�� �������� ��" NOR; 
                     case "(creator)": 
                             return YEL "�� �����ѡ ��" NOR; 
                     case "(apprentice)": 
                             return CYN "�� ����ѧͽ ��" NOR; 
                     case "(immortal)": 
                             return CYN "�� ��    �� ��" NOR;   
                default:
                switch(ob->query("family/family_name")) {
                        case "������":
                                if (maha >= 400 )
                                        return HIW "�� �������� ��" NOR;
                                else if (maha >= 300)
                                        return WHT"�� ��    �� ��" NOR;
                                else if (maha >= 200)
                                        return WHT"�� ��    �� ��" NOR;
                                else if (maha >= 100)
                                        return "�� ��    �� ��" NOR;
                        
                                else   return "�� С    �� ��" NOR;
 

                case "ȫ���":
                        if (taoism >= 500)
                                return HIW "�� �� �� ͨ ��" NOR;
                        else if (taoism >= 450)
                                return HIC"�� ��    �� ��" NOR;
                        else if (taoism >= 400)
                                return HIC"�� ��    ʦ ��" NOR;
                        else if (taoism >= 300)
                                return HIG"�� ��    �� ��" NOR;
                        else if (taoism >= 200)
                                return HIG"�� ��ѧ��ʦ ��" NOR;
                        else if (taoism >= 100)
                                return "�� ��ѧ��ʦ ��" NOR;
                        else
                                return     "�� С �� ʿ ��" NOR;

                        case "����μ�":
                                if (dlrank==5)
                                        return HIW"�� ��    ү ��" NOR;
                                else if (dlrank==4)
                                        return HIC"�� ��    ү ��";
                                else if (dlrank==3)
                                        return "�� ��    �� ��";
                                else if (dlrank<=2)
                                        return "�� ��    �� ��";
                        case "ؤ��":            
                                if (htqg >= 550)
                                        return HIW "�� ��    ؤ ��" NOR;
                                else if (htqg >= 450)
                                        return HIC"�� ִ������ ��" NOR;
                                else if (htqg >= 400)
                                        return HIC"�� �������� ��" NOR;
                                else if (htqg >= 300)
                                        return HIG"�� ������ͷ ��" NOR;
                                else if (htqg >= 200)
                                        return HIG"�� �ư���ͷ ��" NOR;
                                else if (htqg >= 100)
                                        return "�� ؤ����� ��" NOR;
                                else
                                        return "�� С �� �� ��" NOR;
                        case "�䵱��":
                                if (tjsg >= 500)
                                        return HIW "�� ����һ�� ��" NOR;
                                else if (tjsg >= 400)
                                        return HIC"�� ��    �� ��" NOR;
                                else if (tjsg >= 300)
                                        return HIG"�� �䵱���� ��" NOR;
                                else if (tjsg >= 150)
                                        return HIG"�� �䵱���� ��" NOR;
                                else
                                        return "�� С �� ͯ ��" NOR;
                        case "�һ���":
                                if (btxg >= 500)
                                        return HIW "�� ��    а ��" NOR;
                                else if (btxg >= 450)
                                        return HIC"�� С �� а ��" NOR;
                                else if (btxg >= 400)
                                        return HIC"�� ռ �� ʦ ��" NOR;
                                else if (btxg >= 300)
                                        return HIG"�� ��    ʿ ��" NOR;
                                else if (btxg >= 150)
                                        return HIG"�� �� �� �� ��" NOR;
                                else if (btxg >= 100)
                                        return "�� �һ����� ��" NOR;

                                else
                                        return "�� �һ����� ��" NOR;
                        case "������":
                                if (hgdf >= 500)
                                        return HIW "�� �������� ��" NOR;
                                else if (hgdf >= 400)
                                        return HIC"�� ���޻��� ��" NOR;
                                else if (hgdf >= 300)
                                        return HIG"�� ����ʹ�� ��" NOR;
                                else if (hgdf >= 200)
                                        return HIG"�� ���޴��� ��" NOR;
                                else if (hgdf >= 100)
                                        return "�� ����С�� ��" NOR;
                                else
                                        return "�� ���޵��� ��" NOR;

                        case "����ɽ":
                                if (hama >= 600)
                                        return HIW "�� ��    �� ��" NOR;
                                else if (hama >= 500)
                                        return HIC"������ɽ���ˡ�" NOR;
                                else if (hama >= 400)
                                        return HIC"������ɽ������" NOR;
                                else if (hama >= 300)
                                        return HIG"������ɽ�ܼҡ�" NOR;
                                else if (hama >= 200)
                                        return HIG"������ɽ���֡�" NOR;
                                else
                                        return "������ɽ��ʦ��" NOR;
                        case "������":
                                if (qqsh >= 400)
                                        return HIW "�� ״    Ԫ ��" NOR;
                                else if (qqsh >= 350)
                                        return HIC"�� ��    �� ��" NOR;
                                else if (qqsh >= 300)
                                        return HIG"�� ̽    �� ��" NOR;
                                else if (qqsh >= 200)
                                        return "�� ��    ʿ ��" NOR;
                                else if (qqsh >= 100)
                                        return "�� ��    �� ��" NOR;
                                else
                                        return "�� ѧ    ʿ ��" NOR;

        
                        case "��ɽ��":
                                if ( zxg >= 500 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIW "�� ��    �� ��" NOR;
                                else if (zxg >= 500)
                                        return HIW "�� ��    ʥ ��" NOR;
                                else if (zxg >= 360 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIC"�� ���ڸ��� ��" NOR;
                                else if (zxg >= 360)
                                        return HIC"�� ���ڸ��� ��" NOR;
                                else if (zxg >= 200 && ob->query_skill("dugu-jiujian",1)>50 )
                                        return HIG"�� ���ڵ��� ��" NOR;
                                else if (zxg >= 200)
                                        return HIG"�� ���ڵ��� ��" NOR;
                                else
                                        return "����ɽС���͡�" NOR;

                        case "��Ĺ��":
                                if (ynxj >= 500)
                                        return HIW "�� ��    ʥ ��" NOR;
                                else if (ynxj >= 450)
                                        return HIC"�� ��    �� ��" NOR;
                                else if (ynxj >= 350)
                                        return HIC"�� ���齣�� ��" NOR;
                                else if (ynxj >= 200)
                                        return HIG"�� �� �� �� ��" NOR;
                                else if (ynxj >= 100)
                                        return "�� ��Ĺ���� ��" NOR;
                                else
                                        return "����ĹС���͡�" NOR;
                                
                        case "������":
                                if (budd >= 500)
                                        return HIW "�������ó��ϡ�" NOR;
                                else if (budd >= 450)
                                        return HIY"����ĦԺ������" NOR;
                                else if (budd >= 400)
                                        return HIY"���޺���������" NOR;
                                else if (budd >= 350)
                                        return HIY"�� ��    �� ��" NOR;
                                else if (budd >= 300)
                                        return HIY"�� ʥ    ɮ ��" NOR;
                                else if (budd >= 250)
                                        return HIY"�� ��    �� ��" NOR;
                                else if (budd >= 200)
                                        return "�� ��    �� ��" NOR;
                                else if (budd >= 150)
                                        return "�� ��    ʦ ��" NOR;
                                else if (budd >= 100)
                                        return "�� ��    �� ��" NOR;
                                else
                                        return "�� ɮ    �� ��" NOR;
                                
                
                        case "ѩɽ��":
                                if ( lama>= 550)
                                        return HIW "�� ��    �� ��" NOR;
                               else if (lama >= 500)
                                        return HIY"�� ת �� �� ��" NOR;
                                else if (lama >= 400)
                                        return HIY"�� ��    �� ��" NOR;
                               else if (lama >= 300)
                                        return HIY"�� ��    �� ��" NOR;
                                else if (lama >= 200)
                                        return HIY"�� ��    ʦ ��" NOR;
                                else if (lama >= 100)
                                        return "�� �� �� �� ��" NOR;
                                else
                                        return "�� ��    ͯ ��" NOR;

                        default:
                                if (ob->query("combat_exp") > 1000000)
                                        return  "�� �������� ��" NOR;
                                else   return  "�� ƽ    �� ��" NOR;

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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ̫";
                                else return "ʦ̫";
                                break;

                        case "taoist":
                                if( age < 18 ) return "С�ɹ�";
                                else return "�ɹ�";

                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "����";
                                else if (ob->query("dali/rank")==4)
                                        return "�����";
                                else {
                                        if( age < 18 ) return "С����";
                                        else if( age < 50 ) return "����";
                                        else return "����";
                                }
                                break;
                        default:
                                if( age < 18 ) return "С����";
                                else if( age < 50 ) return "����";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ��";
                                else return "��ʦ";
                                break;
                        case "lama":
                                if( age < 25 ) return "Сʦ��";
                                else return "����";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С����";
                                else return "����";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "С�ϵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ǰ��";
                                break;
                        case "eunach":
                                if (ob->query_skill("pixie-jian",1)>160)
                                        return "����";
                                if (age <18) return "С����";
                                else if (age < 50) return "����";
                                else return "�Ϲ���";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "��ү";
                                else if (ob->query("dali/rank")==4)
                                        return "��ү";
                                else if (ob->query("dali/rank")==3)
                                        return "����";
                                else return "��ү";
                                break;
                        default:
                                if( age < 20 ) return "С�ֵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ү��";
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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "����";
                                break;
                        case "taoist":
                                return "��Ů";
                                break;
                        default:
                                if( age < 18 ) return "С����";
                                else if( age < 50 ) return "����";
                                else return "����̫��";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "��ͺ¿";
                                else return "��ͺ¿";
                                break;
                        case "lama":
                                if( age < 50 ) return "��ͺ¿";
                                else return "��ͺ¿";
                                break;
                        case "taoist":
                                return "��ţ����";
                                break;
                        case "eunach":
                                return "����";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "����";
                                else if (ob->query("dali/rank")>=3)
                                        return "����";
                                else return "������";
                                break;
                        default:
                                if( age < 20 ) return "С���˵�";
                                if( age < 50 ) return "����";
                                else return "��ƥ��";
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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        default:
                                if( age < 30 ) return "СŮ��";
                                else if( age < 50 ) return "���";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶɮ";
                                else return "����";
                                break;
                        case "lama":
                                if( age < 50 ) return "ƶɮ";
                                else return "����";
                                break;
                        case "eunach":
                                return "�¹�";
                                break;
                        case "taoist":
                                return "ƶ��";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "С����";
                                else return "�¹�";
                                break;
                        default:
                                if( age < 50 ) return "����";
                                else return "��ͷ��";
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
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        default:
                                if( age < 30 ) return "������";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "�������";
                                else return "�Ϻ�����";
                                break;
                        case "eunach":
                                if (age < 50) return "����";
                                else return "����";
                                break;
                        case "lama":
                                if( age < 50 ) return "����ү";
                                else return "�Ϸ�ү��";
                                break;  
                        case "taoist":
                                return "��ɽ��";
                                break;
                        case "officer":
                                if (ob->query("dali/rank")==5)
                                        return "����";
                                else if (ob->query("dali/rank")==4)
                                        return "����";
                                else if (ob->query("dali/rank")==3)
                                        return "����";
                                else return "��ү��";
                                break;
                        default:
                                if( age < 50 ) return "��ү��";
                                else return "����";
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
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        case "����" :
                if (ob->query("class")== "eunach") {
                if (a1 >= a2)
                        if (random(5)==1) return "����";
                        else return "�ܵ�";
                else
                        if (random(5)==1) return "���";
                        else return "���";
                }
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
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
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }
}
