//[xiaojl 1999/11/20 ���ִ���]
//buwu �޸��� 2001/10/7
//Modified by tracy 6/1/2002 for wizre
#define GXD_DIR       "/u/felix/gxd/"
#define GXD_FILENAME  "gxd"
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_SAVE;
mapping *notes;
string query_save_file()
{
        return GXD_DIR + GXD_FILENAME ;
}
void done_post(object me, mapping note, string text)
{
    int i; //line 20
    note["msg"] = text;
    i = sizeof(notes);
    for( ; i > 0; i-- ) 
        if( notes[i-1]["author"] == me->query("id") ) break;
    if( !pointerp(notes) || i > 0 )
        if(!sizeof(notes)) notes = ({ note });
        else {
            notes[i-1]["title"] = note["title"];
            notes[i-1]["author"] = note["author"];
            notes[i-1]["msg"] = note["msg"];
            notes[i-1]["time"] = note["time"];
            notes[i-1]["solve"] = "";
            notes[i-1]["wizre"] = "";     
      }
    else
        notes += ({ note });
    tell_object(me, CYN "���׶�������Ϣ����ɹ������������ɴ��лл��ĺ�����\n");
    tell_object(me, CYN "�����������ڴ���������ҵ����⣬����΢�ȴ�һ�¡�\n");
    tell_object(me, CYN "������� gxd read ���鿴�Ƿ��������˹��׶ȡ�\n" NOR);
    message("channel:sys",HIR"��GXD����"+me->query("name")+"�������׶����롣\n"NOR,users());
    save();
    return;
}
void list_bug(object me)
{
    int i;
    string str,s;
    if (sizeof(notes)<1) {
        write("û�˷��� gxd ���׶����롣\n");
        return;
    } 
    s = sprintf("����Ѿ������� gxd �����б�����:\n"
                HIW"==------------------------------------------------------------------=="NOR"\n");
    for( i = 0; i<sizeof(notes); i++){
        str = sprintf("%d) %-50s %10s %s %s \n",
                           i+1, notes[i]["title"], notes[i]["solve"]==""?"No solved":"By "+notes[i]["solve"],
                                               notes[i]["wizre"]==""?"":HIM"�ظ�"NOR,
                           ctime(notes[i]["time"])[0..9] );
        s = s + str;
    }
    me->start_more(s);                
}
void do_read(object me, int i) 
{
    string s,str;
    if( i > sizeof(notes) || i < 1) {
        write("�޴˱��!!\n");
        return;
    }
    s = sprintf("%d) %-50s %10s %s\n"
                HIW"________________________________________________________________________"NOR"\n"
              "%s",
               i, notes[i-1]["title"], notes[i-1]["solve"]==""?"No solved":"By "+notes[i-1]["solve"],
               ctime(notes[i-1]["time"])[0..9], notes[i-1]["msg"] );
       if (notes[i-1]["wizre"]!="" && notes[i-1]["solve"]!="") 
       {
 str = sprintf(HIW"________________________________________________________________________"NOR"\n"
                          "����""(%s)" "����� �ظ���:\n\n" "%s",
               notes[i-1]["solve"],notes[i-1]["wizre"] );
       s=s+str;
       }
    me->start_more(s);
}
int search_id(string id)
{
    int i;
    if( !(i = sizeof(notes)) ) return 0;
    for( ; i > 0; i-- ) 
        if( notes[i-1]["author"] == id ) break;
    return i;
}
int do_solve(object me, int i)
{
    if( i > sizeof(notes) || i < 1) {
        write("�޴˱��!!\n");
        return 0;
    } 
    if ( notes[i-1]["solve"]!="" ) {
        write(notes[i-1]["solve"]+"�Ѿ���־��!\n");
        return 1;
    }
    notes[i-1]["solve"] = me->query("id");
    save();
    write("�� gxd �����ѱ�־Ϊ�����\n");
    return 1;
}
void do_wizre(object me, int i,string text)
{
    if( i > sizeof(notes) || i < 1) {
        write("�޴˱��!!\n");
        return;
    } 
    if ( notes[i-1]["wizre"]!="" ) {
        write(notes[i-1]["solve"]+"�Ѿ��ظ���!\n");
        return;
    }
      notes[i-1]["solve"] = me->query("id");
     notes[i-1]["wizre"] = text; 
     save();
     write("��gxd�����־�˲��ظ�!\n");
     return;
}
int main(object me, string arg)
{
    mapping note;
    object where;
    string s, str,arg1; //line 40
    int i,arg2;
//    if (file_size(SOS_DIR + SOS_FILENAME) == -1) {
  //      notes = ({ });
    //    save();
    //}
    restore();
    if (!arg) {
        if(!wiz_level(me)){
            tell_object(me, CYN "������Ϊ�Լ�Ϊ"HIW"�����ݡ�"NOR""CYN"������׿Խ�Ĺ��ס�\n");
            tell_object(me, CYN "����Ժ�����ԥ����������������׶����룺"HIR"�ǣأģ�����\n" NOR);
            where = environment(me);
            if (!where) 
                s=sprintf("%s(%s)��������",
                        (string)me->name(),
                        (string)me->query("id"));
            else
                s=sprintf("%s(%s)��%s(%s)��������",
                        (string)me->name(),
                        (string)me->query("id"),
                        (string)where->query("short"),
                        (string)file_name(where));
            note = allocate_mapping(6);
            note["title"] = s;
            note["author"] = me->query("id"); 
            note["time"] = time();
            note["solve"] = "";
            note["wizre"] = ""; 
            me->edit( (: done_post, me, note :) );
        }
        else {
            list_bug(me);
        }
        return 1;
    } 
    if( sscanf(arg, "%s %d", s, i) == 2 ) {
        if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n"); 
        if ( s != "solve" && s!= "wizre") return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
              if (s=="solve")   do_solve( me, i );
             if(s=="wizre" )  
              {
                            if( i > sizeof(notes) || i < 1) {
                       write("�޴˱��!!\n");
                    return 1;
              }
                if ( notes[i-1]["wizre"]!="" ) {
                          write(notes[i-1]["solve"]+"�Ѿ��ظ���!\n");
                 }
                else 
                {
                  if( i > 0 ) { 
                         me->edit( (: do_wizre, me,i:) );
                             }
                }
        }
                               return 1;
       }
 if( sscanf(arg, "%s %s", s, arg1) == 2 ) {
        if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
         switch(s){
              case "solve": 
         if ( arg1 =="all" ) {
                         if( !(i = sizeof(notes)) ) return notify_fail("û�˷���gxd���롣\n");
                  for( ; i > 0; i-- ) 
               notes[i-1]["solve"] = me->query("id");
                  write("���е� gxd ��Ϣ�Ѿ���־Ϊ����ˡ�\n");
                  return 1;
                       }
                   break;
              case "wizre":
                         break;
              default: 
                   return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
                   break;    
        }
                                i = search_id(arg1);
                if (s=="wizre")
                {
                         if (i > 0)
                        if ( notes[i-1]["wizre"]!="" ) {
                          write(notes[i-1]["solve"]+"�Ѿ��ظ���!\n");
                          return 1;
                         }
            
                      else 
                          {
                  if( i > 0 ) { 
                         me->edit( (: do_wizre, me,i:) );
                        return 1;
                             }
                         }
                 }
        if (s=="solve")
          {
            if( i > 0 ) { 
                        do_solve( me, i );
                       return 1;
           }
          }
     }
    if ( sscanf(arg, "%s", s) == 1 ) 
    switch(arg){
        case "read":       
            if( !(i = sizeof(notes)) )
                return notify_fail("��û�����ύ�� gxd ���룡\n");
            else {
                i = search_id( me->query("id") );
                do_read(me,i);
            }
            break;
        case "list":
            if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
            list_bug(me);
            break;
        case "pack":
                    if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
            if( !(i = sizeof(notes)) ) return notify_fail("û�˷��� gxd ���롣\n"); 
                for( ; i > 0; i-- ) 
                if( "" != notes[i-1]["solve"] ) {
                                 if (notes[i-1]["wizre"]=="")
                                 {
                    printf("%s�� gxd �����ѱ�ɾ����\n", notes[i-1]["author"]);
                    if( sizeof(notes) == 1 ) notes = ({});
                    else if(i==1) notes = notes[1..sizeof(notes)-1];
                    else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
                    else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];       
                                 }
else if (notes[i-1]["wizre"]!="" && me->query("id")=="tracy" || wizhood(me) == "(arch)" || wizhood(me) == "(admin)")
                                  {
                    printf("%s�� gxd �����ѱ�ɾ����\n", notes[i-1]["author"]);
                    if( sizeof(notes) == 1 ) notes = ({});
                    else if(i==1) notes = notes[1..sizeof(notes)-1];
                    else if( i == sizeof(notes) ) notes = notes[0..sizeof(notes)-2];
                    else notes = notes = notes[0..i-2] + notes[i..sizeof(notes)-1];        
                    }                               
                            }
                              save();
                              break;   
        case "solve":
            if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
            return notify_fail("��ʽ: gxd solve <��Ż����id>\n");
            break;
        default:
            if( !wiz_level(me) ) return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
            if( sscanf(arg, "%d", i) == 1 )
                do_read( me, i );
            else if( sscanf( arg, "%s", str ) == 1 ) {
                i = search_id(str);
                if( i == 0 ) return notify_fail("�޴���ҷ����� gxd ���룡\n");
                do_read( me, i );
            }
    }
    else return notify_fail("��ʽ���ԣ�����ʹ�÷�������� help gxd \n");
    return 1;
}
int help(object me)
{
        if (!wiz_level(me) )
        write(@HELP
ָ���ʽ : 
           gxd
           gxd read
���ָ�����������Ҫ��ʦΪ����ӹ��׶ȵ�ʱ������ʦ������롣��
��������ϵͳ����ʾ�����빱�׶���������ɡ��뽫�����빱�׶�
���¼������빱�׶ȵĶ��٣��ֱ�ע�����Ա���ʦ�������ٶ�Ϊ����
�ӹ��׶ȡ�
Ϊ�������ʦ��Ч�ʣ�����ʹ�� gxd ����ǰ����ϸ�Ķ� help gongxian��
��ҿ����� gxd read �Ķ��Լ������Ĺ��׶����롣
HELP
    );
        else 
write(@HELP
ָ���ʽ : 
           gxd <��������id>
           gxd list
           gxd pack
           gxd solve <��������id>
                   gxd wizre <��������id>
���ָ����Ը�����ʦ�����������Ĺ��׶����롣gxd list �ǽ�����
�� GXD ��������б��������� gxd ������ݲ����Ĳ�ͬ������ʾ��
Ӧ������Ӧ��ҵĹ��׶�������Ϣ��gxd solve ������־ĳ�����׶���
�뾭������ˡ�gxd pack ��ɾ�������Ѿ���־Ϊ����˵Ĺ��׶����룬
gxd wizre�����ظ���ҡ�
HELP
    );
    return 1;
}
