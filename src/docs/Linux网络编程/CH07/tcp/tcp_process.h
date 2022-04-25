/*
 * @Date: 2022.04.25 15:33
 * @Description: Omit
 * @LastEditors: Rustle Karl
 * @LastEditTime: 2022.04.25 15:33
 */
#ifndef TCP__TCP_PROCESS_H
#define TCP__TCP_PROCESS_H

void process_conn_server(int);
void process_conn_client(int);
void sig_process(int);
void sig_pipe(int);

#endif//TCP__TCP_PROCESS_H
