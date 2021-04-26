// doc.c
// atu@sjfy
// Last Modified by jjgod@vrhf.
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object);   
void QueryNpcInfo(string);
void QueryRoomInfo(string);
void QueryItemInfo(string);
string QuerySkill(object);
string QueryAction(object,object);
string QueryEquipProp(object,mapping);

int main(object me,string arg)
{
    string path,var;
    string *filename;

    if( !arg || sscanf(arg,"%s %s",path,var) != 2){
        return help(me);
    }
    if(file_size(path = resolve_path(me->query("cwd"),path)) != -2 )
        return notify_fail("û�����Ŀ¼��\n");
    seteuid(getuid());
    if(path[sizeof(path)-1] != '/')
        path += "/";
    switch(var)
    {
        case "-npc":
        case "-NPC":
            QueryNpcInfo(path);
            break;
        case "-room":
        case "-ROOM":
            QueryRoomInfo(path);
            break;
        case "-item":
        case "-ITEM":
            QueryItemInfo(path);
            break;
        default:
            write("�������ԣ����������룡\n");
            break;
    }
    return 1;
}
void QueryNpcInfo(string path)
{
    string filename;
    string *file;
    object obj,me=this_player();
    int num=0;
    filename=path+"�ĵ�����֮NPCƪ";
    
    if(file_size(filename)>0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(tmp) == -2)
            continue;
        write(sprintf("  ����%-15s����...",tmp));
        reset_eval_cost();
        obj=new(path + tmp);
        if (!objectp(obj) ){
            write(RED" ...ʧ�ܣ�\n"NOR);
            continue;
        }
        if(!obj->is_character() || !obj->query("name")){
            write(RED"NOT NPC��\n"NOR);
            continue;
        }
        num ++;
    write_file(filename,GRN"==================================================\n"NOR,0);
    write_file(filename,RED"�ļ���ţ�"NOR+num+"\n",0);
    write_file(filename,RED"�ļ����ƣ�"NOR+tmp+"\n",0);
    write_file(filename,WHT"�������֣�"NOR+obj->query("name")+"\n",0);
    write_file(filename,WHT"Ӣ�ģɣ�: "NOR + sprintf("%s",implode(obj->parse_command_id_list(), ","))+"\n",0);
    write_file(filename,QuerySkill(obj),0);
    write_file(filename,"��������������������������������������������������\n");
 
 
    write_file(filename,sprintf("��  ��  ��%10d      �� ���� ��%d \n",
            obj->query("max_jing"),obj->query("max_jingli")));
    write_file(filename,sprintf("��  ��  ��%10d      �� ���� ��%d (+%d)\n",
            obj->query("max_qi"),obj->query("max_neili"),obj->query("jiali")));
    write_file(filename,sprintf("�� ʳ�� ��%10d      �� Ǳ�� ��%d \n",
            obj->query("food"),obj->query("potential")));
//    write_file(filename,sprintf("�� ��ˮ ��%10d      �� ���� ��%s \n",
//            obj->query("water"),obj->query("combat_exp")));
 
 
        destruct(obj);
        write(YEL" ...�ɹ��� \n"NOR);
    }
    write_file(filename,"==================================================\n",0);
    write_file(filename,"    ��Ŀ¼���ܹ���"GRN+num+NOR"��NPC�ļ���\n",0);
    write("=========================================\n");
    write("      ������"GRN+chinese_number(num)+NOR"����NPC�ļ�   \n\n");
       me->start_more(read_file(filename,1));
}
void QueryRoomInfo(string path)
{
    string filename;
    string *file;
    object obj;
    object finder=new("/clone/npc/trashcan");
       object me=this_player();
    int num=0;
    filename=path+"�ĵ�����֮ROOMƪ";
    
    if(file_size(filename)>0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(path+tmp) == -2)
            continue;
        write(sprintf("  ����%-15s����...",tmp));
        reset_eval_cost();
        obj=load_object(path+tmp);
        if (!objectp(obj) ){
            write(RED" ...ʧ�ܣ�\n"NOR);
            continue;
        }
        if( obj->is_character() || !stringp(obj->query("short")) ){
            write(RED"NOT ROOM\n"NOR);
            continue;
        }
        num ++;
        write_file(filename,"��������������������������������������������������\n",0);
        write_file(filename,YEL"������ţ�"WHT+num+"\n"NOR,0);
        write_file(filename,YEL"�������ƣ�"WHT+obj->query("short")+"("+tmp+")\n"NOR,0);
        write_file(filename,YEL"�������꣺"WHT"��"+obj->query("coor/x")+","
                   +obj->query("coor/y")+","+obj->query("coor/z")+"��\n"NOR,0);
        write_file(filename,QueryAction(obj,finder),0);
        if(mapp(obj->query("coor")))
            write(YEL" ...�ɹ�\n"NOR);
        else
            write(YEL" ...�ɹ�"RED"�������꣩\n"NOR);
    }
    write_file(filename,"==================================================\n",0);
    write_file(filename,"    ��Ŀ¼���ܹ���"GRN+num+NOR"�����䣡\n",0);
    write("=========================================\n");
    write("      ������"GRN+chinese_number(num)+NOR"���������ļ�   \n\n");
       me->start_more(read_file(filename,1));
    destruct(finder);
}
void QueryItemInfo(string path)
{
    string filename;
    string *file;
    object obj;
    mapping prop;
       object me=this_player();    
    int num=0;
    int flag=0;
    filename=path+"�ĵ�����֮ITEMƪ";
    
    if(file_size(filename)>0)
        rm(filename);
    file=get_dir(path);
    foreach(string tmp in file){
        if (file_size(path+tmp) == -2)
            continue;
        write(sprintf("  ����%-15s����...",tmp));
        reset_eval_cost();
        obj=new(path + tmp);
        if (!objectp(obj) ){
            write(RED" ...ʧ�ܣ�\n"NOR);
            continue;
        }
        if( obj->is_character() || !stringp(obj->query("name")) ){
            write(RED"NOT ITEM\n"NOR);
            continue;
        }
        num ++;
        write_file(filename,GRN"��������������������������������������������������\n"NOR,0);
        write_file(filename,WHT"��Ʒ��ţ�"NOR+num+"\n",0);
        write_file(filename,WHT"��Ʒ���ƣ�"NOR+obj->query("name")+"("+
                    implode(obj->parse_command_id_list(),",")+")\n",0);
        write_file(filename,WHT"��Ʒ�۸�"NOR+MONEY_D->price_str((int)obj->query("value"))+"\n",0);
/*
        if(mapp(prop=obj->query("weapon_prop")))
            QueryEquipProp(obj,prop);
        else if(mapp(prop=obj->query("armor_prop")))
            QueryEquipProp(obj,prop);
*/
        destruct(obj);
        write(YEL" ...�ɹ��� \n"NOR);
    }
    write_file(filename,"==================================================\n",0);
    write_file(filename,"    ��Ŀ¼���ܹ���"GRN+num+NOR"����Ʒ��\n",0);
    write("=========================================\n");
    write("      ������"GRN+chinese_number(num)+NOR"������Ʒ�ļ�   \n\n");
       me->start_more(read_file(filename,1));
}
string QueryAction(object ob,object finder)
{
    mixed *cmds;
    string msg="",*str,name;
    int count=0;

    if (stringp(ob->query("short")))
        name=ob->query("short");
    else name=ob->query("name");

    finder->move(ob);
    cmds = finder->query_commands();
    if ( sizeof(cmds) == 1) return("");
    msg += "          "CYN+name +"�ṩ����ָ�\n"NOR;
    foreach(mixed cmd in cmds){
        if( cmd[2]==finder ) continue;
        msg+=sprintf(WHT"%-10s   "NOR, cmd[0]);
        count++;
        if(count%4==0)
            msg+="\n";
    }
    msg+="\n";
    return msg;
}
string QuerySkill(object ob)
{
    mapping m_skills,m_enable;
    string *sname;
    int i, jibie, lingwu, jilei,xiuwei, opt_all;    
    string msg="";

    m_skills = ob->query_skills();
    if ( !sizeof(m_skills) )
        return("");
    msg += "          "+ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n";
    m_enable = ob->query_skill_map();
    if ( !mapp(m_enable) ) m_enable = ([]);
    sname=keys(m_skills);
    msg=msg+"��������������������������������������������������\n";
    for ( i = 0; i < sizeof( m_skills ); i++ ){
        msg=msg+sprintf( "%s%-12s%-28s%8d\n",
            m_enable[ sname[i] ] ? WHT"��"NOR : "  ",
            to_chinese(sname[i]),  " ��" + sname[i] + "��",
            m_skills[sname[i]]);        
        }
    return msg;
}
string QueryEquipProp(object equip,mixed props)
{
    string type,msg="";
    int *special_props,i;
    int count=0;
    string *prop;

    if(stringp(type=equip->query("skill_type")))
        msg+=sprintf("�������ͣ�%-10s     �� �� ����%d",type,(int)equip->query("weapon_porp/damage"));
    else if(stringp(type=equip->query("skill_type")))
        msg+=sprintf("�������ͣ�%-10s     �� �� ����%d",type,(int)equip->query("armor_porp/armor"));
    if ( !sizeof(props)) return("");
    msg += "          "+equip->name()+"��������Ч��\n";
    prop=keys(props);
    for (i=0;i<sizeof(props);i++){
// foreach(string prop in props){
        if( prop[i]=="armor"||prop[i]=="damage")
            continue;
        msg+=sprintf(WHT"%-12d  "NOR, props[prop[i]]);
        if(i%4==0)
            msg+="\n";
    }
    return msg;
}

int help(object me)
{
    write(@HELP
ָ���ʽ��doc ·���� -������ 
Ŀǰ�ṩ�������У�room��npc��item
����
    doc /d/city/npc -npc
���������ʱ��ò�ʹ�ô�ָ�
HELP);
    return 1;
}