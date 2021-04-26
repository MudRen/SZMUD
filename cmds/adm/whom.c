//Code of ShenZhou
// who.c
// modified by xuy 07/29/97

#include <ansi.h>
#include <net/daemons.h>
#include <net/dns.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

#define O_SHAOLIN   0x1;
#define O_WUDANG    0x2;
#define O_GAIBANG   0x4;
#define O_EMEI      0x8;
#define O_HUASHAN   0x10;
#define O_DALI      0x20;
#define O_TAOHUA    0x40;
#define O_XINGXIU   0x80;
#define O_SHENLONG  0x100;
#define O_XUESHAN   0x200;
#define O_XUEDAO    0x200;
#define O_BAITUO    0x400;
#define O_QUANZHEN  0x800;
#define O_GUMU  0x1000;
#define O_LINGJIU  0x2000;
#define O_KUNLUN  0x4000;
#define O_OTHER     0x8000;
string blank_string = "                           ";
string tribar_graph(int a);
void create() { seteuid(getuid()); }

int isPlayer( object obj )
{
    if ( interactive( obj ) ) 
        return 1;
    if ( obj->query( "scheming" ) )
        return 1;
    return 0;
}

object *allusers()
{
    return children(USER_OB);
}

mixed main(object me, string arg, int remote)
{
    string str, msgs, space, *option, *sites, space2;
    object *list;
    int i, j, ppl_cnt, total, s;
    int opt_long, opt_id, opt_wiz, family=0, x, y;
    if( arg ) 
    {
        option = explode(arg, " ");
        i = sizeof(option);
        while( i-- )
            switch(option[i]) 
            {
            case "-l":  opt_long = 1;   break;
            case "-i":  opt_id = 1; break;
            case "-w":  opt_wiz = 1;    break;
            case "-quanzhen":family |= O_QUANZHEN;  break;
            case "-gumu":family |= O_GUMU;  break;
                    case "-kunlun":family |= O_KUNLUN;  break;
            case "-shaolin":family |= O_SHAOLIN;    break;
            case "-wudang": family |= O_WUDANG; break;
            case "-gaibang":family |= O_GAIBANG;    break;
            case "-emei":   family |= O_EMEI;  break;
            case "-huashan":family |= O_HUASHAN; break;
            case "-dali":   family |= O_DALI; break;
            case "-taohua": family |= O_TAOHUA; break;
            case "-xingxiu":family |= O_XINGXIU; break;
            case "-lingjiu": family |= O_LINGJIU; break;
            case "-shenlong":family|= O_SHENLONG; break;
            case "-xueshan":family |= O_XUESHAN; break;
            case "-xuedao": family |= O_XUEDAO; break;
            case "-baituo": family |= O_BAITUO; break;
            case "-other" : family |= O_OTHER; break;
            default:
                if( remote ) break;
            if( option[i][0]=='@' ) 
            {
                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
                            me, arg);
                write("��·ѶϢ���ͳ������Ժ�\n");
                return 1;
            }
            return notify_fail("ָ���ʽ��who [-l|-i|-w|-shaolin|-wudang|...] [@site]\n");
        }
    }

    if( !remote && opt_long && wizardp(me)) 
    {
        if( (int)me->query("jing") < 30 )
            return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
        me->receive_damage("jing", 30);
    }
    
    if (opt_wiz && me ) 
    {
        sites = keys(DNS_MASTER->query_svc());
        j = sizeof(sites);
        for(i=0; i<j; i++)
            RWHO_Q->send_rwho_q(sites[i], me, arg);
    }
    
    str = sprintf(CYN"��" + INTERMUD_MUD_CNAME + "��"HIW"Ŀǰ���ߵ�%s�У�"NOR"\n",opt_wiz?"��ʦ":"���");
    str += "��������������������������������������������������������������������������\n";
    
    list = filter_array(allusers(), (: isPlayer :));
    
    total = sizeof(list);
    if (family) list = filter_array(list, "filter_user", this_object(), family);
    list = sort_array(list, "sort_user", this_object());
    if( opt_long || opt_wiz ) 
    {
        ppl_cnt = 0;
        j = sizeof(list);
        while( j-- ) 
        {
                // Skip those users in login limbo.
            if( !environment(list[j]) ) continue;
            if( me && !me->visible(list[j]) ) continue;
            if( opt_wiz && !wizardp(list[j]) ) continue;
            if ( list[j]->query( "id" ) == "mariner" || list[j]->query( "id" ) == "buwu" ) continue;
            if ( interactive( list[j] ) )
            {	    
                str = sprintf("%s%12s%s%s\n",
                        str, RANK_D->query_rank(list[j]),
                        list[j]->short(1),
                        query_idle(list[j]) > 120?HIM "<������>" NOR:" ");
            }
            else if( list[j]->query( "scheming" ) )
            {
                str = sprintf("%s%12s%s%s\n",
                        str, RANK_D->query_rank(list[j]),
                        list[j]->short(1),
                        HIM "<����������>"NOR);                
            }  
            ppl_cnt++;
        }
        msgs = " ";
    } 
    else 
    {
        ppl_cnt = 0;
        j = sizeof(list);
        while( j-- ) 
        {
            // Skip those users in login limbo.
            if( !environment(list[j]) ) continue;
            if ( list[j]->query( "id" ) == "mariner" || list[j]->query( "id" ) == "buwu" ) continue;
            if( me && !me->visible(list[j]) ) continue;
            if(opt_id) s = strlen(list[j]->query("id"));
            else s = strlen(list[j]->name(1));
            if ( interactive( list[j] ) )
            {
                str = sprintf("%s%-15s%s", str,
                    opt_id ? (query_idle(list[j]) > 120?HIM+capitalize(list[j]->query("id"))+NOR+tribar_graph(s):capitalize(list[j]->query("id"))): (query_idle(list[j]) > 120?HIM+list[j]->name(1)+NOR+tribar_graph(s):list[j]->name(1)),
                    (ppl_cnt%5==4? "\n": "")
                    );
                ppl_cnt++;
           }
            else if ( list[j]->query( "scheming" ) )
            {
                 
                str = sprintf("%s%-15s%s", str,
                    opt_id ? HIG+capitalize(list[j]->query("id"))+NOR+tribar_graph(s): HIG+list[j]->name(1)+NOR+tribar_graph(s),
                    (ppl_cnt%5==4? "\n": ""));
                ppl_cnt++;                    
            }     
        }
        msgs = HIM"�ۺ�ɫ"NOR" ��ʾ�����е�ʹ���ߡ�";
        if( ppl_cnt%5 ) str += "\n";
    }
    str += "��������������������������������������������������������������������������\n";
    str = sprintf("%s����%sλʹ���������У�ϵͳ������%s%s\n", str, chinese_number(total+20),
    query_load_average()+"\n",msgs);
    
    if( remote ) return (ppl_cnt ? str : 0);
    
    me->start_more(str);
    return 1;
}

string do_who(string arg)
{
    string str, msgs, *option, *sites, space;
    object *list;
    int i, j, ppl_cnt, total, s;
    int opt_long, opt_id, opt_wiz, family=0, y, x;
    
    if( arg ) {
        option = explode(arg, " ");
        i = sizeof(option);
        while( i-- )
            switch(option[i]) 
            {
            case "-l":  opt_long = 1;   break;
            case "-i":  opt_id = 1; break;
            case "-w":  opt_wiz = 1;    break;
            case "-quanzhen":family |= O_QUANZHEN;  break;
            case "-gumu":family |= O_GUMU;  break;
                    case "-kunlun":family |= O_KUNLUN;  break;
            case "-shaolin":family |= O_SHAOLIN;    break;
            case "-wudang": family |= O_WUDANG; break;
            case "-gaibang":family |= O_GAIBANG;    break;
            case "-emei":   family |= O_EMEI;  break;
            case "-huashan":family |= O_HUASHAN; break;
            case "-dali":   family |= O_DALI; break;
            case "-taohua": family |= O_TAOHUA; break;
            case "-xingxiu":family |= O_XINGXIU; break;
            case "-lingjiu": family |= O_LINGJIU; break;
            case "-shenlong":family|= O_SHENLONG; break;
            case "-xueshan":family |= O_XUESHAN; break;
            case "-xuedao": family |= O_XUEDAO; break;
            case "-baituo": family |= O_BAITUO; break;
            case "-other" : family |= O_OTHER; break;
            default:
            }
    }

    
    str = sprintf(CYN"��" + INTERMUD_MUD_CNAME + "��"HIW"Ŀǰ���ߵ�%s�У�"NOR"\n",opt_wiz?"��ʦ":"���");
    str += "��������������������������������������������������������������������������\n";
    list = filter_array(allusers(), (: isPlayer :));
    total = sizeof(list);
    if (family) list = filter_array(list, "filter_user", this_object(), family);
    list = sort_array(list, "sort_user", this_object());
    if( opt_long || opt_wiz ) 
    {
        ppl_cnt = 0;
        j = sizeof(list);
        while( j-- ) 
        {
                // Skip those users in login limbo.
            if( !environment(list[j]) ) continue;
            if( opt_wiz && !wizardp(list[j]) ) continue;
            if ( list[j]->query( "id" ) == "mariner" || list[j]->query( "id" ) == "buwu" ) continue;
            if ( interactive( list[j] ) )
            {	    
                str = sprintf("%s%12s%s%s\n",
                        str, RANK_D->query_rank(list[j]),
                        list[j]->short(1),
                        query_idle(list[j]) > 120?HIM "<������>" NOR:" ");
            }
            else if( list[j]->query( "scheming" ) )
            {
                str = sprintf("%s%12s%s%s\n",
                        str, RANK_D->query_rank(list[j]),
                        list[j]->short(1),
                        HIM "<����������>"NOR);                
            }  
            ppl_cnt++;
        }
        msgs = " ";
    } 
    else 
    {
        ppl_cnt = 0;
        j = sizeof(list);
        while( j-- ) 
        {
            if( !environment(list[j]) ) continue;
            if ( list[j]->query( "id" ) == "mariner" || list[j]->query( "id" ) == "buwu" ) continue;
            if(opt_id) s = strlen(list[j]->query("id"));
            else s = strlen(list[j]->name(1));
            if ( interactive( list[j] ) )
            {
                str = sprintf("%s%-15s%s", str,
                    opt_id ? (query_idle(list[j]) > 120?HIM+capitalize(list[j]->query("id"))+NOR+tribar_graph(s):capitalize(list[j]->query("id"))): (query_idle(list[j]) > 120?HIM+list[j]->name(1)+NOR+tribar_graph(s):list[j]->name(1)),
                    (ppl_cnt%5==4? "\n": "")
                    );
                ppl_cnt++;                    
            }
            else if ( list[j]->query( "scheming" ) )
            {
                 
                str = sprintf("%s%-15s%s", str,
                    opt_id ? HIG+capitalize(list[j]->query("id"))+NOR+tribar_graph(s): HIG+list[j]->name(1)+NOR+tribar_graph(s),
                    (ppl_cnt%5==4? "\n": ""));
                ppl_cnt++;                    
            }               
        }
        msgs = "��"HIC"*"NOR"���Ƿ����е�ʹ���ߡ�";
        if( ppl_cnt%5 ) str += "\n";
    }

    str += "��������������������������������������������������������������������������\n";
    str = sprintf("%s����%sλʹ���������У�ϵͳ������%s%s\n", str, chinese_number(total+20),
    query_load_average() + "\n",msgs);
    return str;
}

int filter_user(object user, int family)
{
    string fam = user->query("family/family_name");
        switch (fam) {
        case "������": return family & O_SHAOLIN; break;
         case "�䵱��": return family & O_WUDANG; break;
         case "ؤ��"  : return family & O_GAIBANG; break;
         case "������": return family & O_EMEI; break;
         case "��ɽ��": return family & O_HUASHAN; break;
         case "����μ�": return family & O_DALI; break;
         case "�һ���": return family & O_TAOHUA; break;
         case "������": return family & O_XINGXIU; break;
         case "���չ�": return family & O_LINGJIU; break;
         case "������": return family & O_SHENLONG; break;
         case "ѩɽ��":
         case "Ѫ����": return family & O_XUESHAN; break;
         case "����ɽ": return family & O_BAITUO; break;
         case "������": return family & O_KUNLUN; break;
         case "ȫ���": return family & O_QUANZHEN; break;
         case "��Ĺ��": return family & O_GUMU; break;
         default:      return family & O_OTHER; break;
    }

    return 0;
}

int sort_user(object ob1, object ob2)
{
    string *family;
    int rank1,rank2, i;
    string family1, family2;

    if( wiz_level(ob1) || wiz_level(ob2) )
        return wiz_level(ob2) - wiz_level(ob1);

    family =
    ({
        "ȫ���",
        "��Ĺ��",
                "������",
        "������",
        "�䵱��",
        "ؤ��",
        "������",
        "��ɽ��",
        "����μ�",
        "�һ���",
        "������",
        "���չ�",
        "������",
        "ѩɽ��",
        "Ѫ����",
        "����ɽ"
    });

    family1 = ob1->query("family/family_name");
    family2 = ob2->query("family/family_name");
    rank1 = member_array(family1, family);
    rank2 = member_array(family2, family);

    if( rank1 > rank2 ) return -1;
    if( rank2 > rank1 ) return 1;

    return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
string tribar_graph(int a)
{
    return BLU + blank_string[0..(14-a)] + NOR;
}
int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-i|-w|-shaolin|-wudang|...] [@site]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-w ֻ�г��������е���ʦ��
-menpai ֻ�г������ɵ���ҡ�menpai ��������������һ����
  shaolin, wudang, gaibang, emei, huashan, dali, taohua,
  shenlong,kunlun, xingxiu, xueshan, xuedao, baituo, other.
@site ��ʾ�����������С�վ�����Ϣ��

������who, who -w, who -i -wudang -emei, who -l -shaolin @sh
���ָ� finger, locate, mudlist
HELP
     );
     return 1;
}
